#ifndef _MAIN
#define _MAIN

#include <iostream>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/Array.hpp"
#include "biblioteca/tads/Map.hpp"
#include "biblioteca/tads/List.hpp"
#include "biblioteca/tads/Stack.hpp"
#include "biblioteca/tads/Queue.hpp"
#include "biblioteca/tads/Coll.hpp"
#include "biblioteca/tads/BitWriter.hpp"
#include "biblioteca/tads/huffman/HuffmanSetup.hpp"
using namespace std;

struct InfoByte
{
   unsigned int n = 0; //cantidad de ocurrencias
   string cod = "";
};

// paso 1 - contar cuantas veces aparece cada byte
void paso1(string nomArchOri, InfoByte arr[])
{

   FILE* f = fopen(nomArchOri.c_str(),"r+b");
   unsigned char byte = read<unsigned char>(f);
   while( !feof(f) )
   {
      arr[byte].n++;
      byte = read<unsigned char>(f);
   }
}

int cmpHuffmanTreeInfo(HuffmanTreeInfo a, HuffmanTreeInfo b)
{
	return a.n!=b.n ? b.n - a.n : b.c - a.c ;
}

// paso 2 - crear la lista y ordenarla
List<HuffmanTreeInfo> paso2(InfoByte arr[])
{
   List<HuffmanTreeInfo> ret = list<HuffmanTreeInfo>();

   for( int i = 0; i<256; i++ )
   {
      if( arr[i].n>0 )
      {
         HuffmanTreeInfo* x = huffmanTreeInfo(i,arr[i].n,NULL,NULL);
         HuffmanTreeInfo y = *(x);
         listOrderedInsert<HuffmanTreeInfo>(ret,y,cmpHuffmanTreeInfo);
      }
   }
   return ret;
}

// paso 3 - convertir la lista en arbol
HuffmanTreeInfo* paso3(List<HuffmanTreeInfo> lst)
{
   int i = 256;
   HuffmanTreeInfo* h1 = listRemoveFirst2<HuffmanTreeInfo>(lst);
   while( !listIsEmpty<HuffmanTreeInfo>(lst) )
   {
      HuffmanTreeInfo* h2 = listRemoveFirst2<HuffmanTreeInfo>(lst);
      HuffmanTreeInfo* x = huffmanTreeInfo(i,(h1->n+h2->n),h2,h1);
      listOrderedInsert<HuffmanTreeInfo>(lst,*x,cmpHuffmanTreeInfo);
      i++;
      h1 = listRemoveFirst2<HuffmanTreeInfo>(lst);
   }
   return h1;
}

// paso 4 - recorrer el arbol y guardar los codigos en el array
void paso4(InfoByte arr[], HuffmanTreeInfo* raiz)
{
   HuffmanTree tree = huffmanTree(raiz);

   while( huffmanTreeHasNext(tree) )
   {
      string cod;
      HuffmanTreeInfo* aux = huffmanTreeNext(tree,cod);
      arr[aux->c].cod = cod;
   }
}

unsigned char cantidadCaract(InfoByte arr[])
{
   unsigned char t = 0;
   for( int i = 0; i<256; i++ )
   {
      if( arr[i].n>0 )
      {
         t++;
      }
   }
   return t;
}

void grabarCod(BitWriter& bw, string cod){
	for(int i =0;i<length(cod);i++){
		int c = charToInt(cod[i]);
		bitWriterWrite(bw,c);
	}
}

// paso 5 - recorrer el archivo original y grabar bit x bit el archivo comprimido
void paso5(string nomArchOri, InfoByte arr[])
{
   string nomArchComp = nomArchOri+".huf";

   FILE* f = fopen(nomArchComp.c_str(),"w+b");
   BitWriter bw = bitWriter(f);
   unsigned char t = cantidadCaract(arr);
   write<unsigned char>(f,t);
   for( int c = 0; c<256; c++ )
   {
      if( arr[c].n>0 )
      {
         unsigned char h = length(arr[c].cod);
         write<unsigned char>(f,c);
         write<unsigned char>(f,h);
         grabarCod(bw,arr[c].cod);
         if(h%8 != 0) bitWriterFlush(bw); //si no es multiplo de 8, rellena con 0
      }
   }
   FILE* ArchOri = fopen(nomArchOri.c_str(),"r+b");
   write<unsigned int>(f,fileSize<unsigned char>(ArchOri));
   unsigned char byteOri = read<unsigned char>(ArchOri);
   while( !feof(ArchOri) )
   {
      string cod = arr[byteOri].cod; // "100"
	  grabarCod(bw,cod);
      byteOri = read<unsigned char>(ArchOri);
   }
   bitWriterFlush(bw);
   fclose(ArchOri);
   fclose(f);
}

void comprimir(string nomArchOri)
{
   InfoByte arr[256];

   // paso 1 - contar cuantas veces aparece cada byte
   paso1(nomArchOri,arr);

   // paso 2 - crear la lista y ordenarla
   List<HuffmanTreeInfo> lista = paso2(arr);

   // paso 3 - convertir la lista en arbol
   HuffmanTreeInfo* raiz = paso3(lista);

   // paso 4 - recorrer el arbol y guardar los codigos en el array
   paso4(arr,raiz);

   // paso 5 - recorrer el archivo original y grabar bit x bit el archivo comprimido
   paso5(nomArchOri,arr);
}

void construirArbol(FILE* f,HuffmanTreeInfo* aux)
{
   BitReader br = bitReader(f);

   unsigned char c = read<unsigned char>(f); //char de hoja
   	int lcod = (int) read<unsigned char>(f); // su longitud
//   	cout<< c<<" --- "<<lcod<<"  ";

  	int a = lcod%8==0 ? lcod: ((lcod/8)+1)*8; //quiero el siguiente múltiplo de 8 mayor a lcod, de esta forma ignoro los ceros de bitWriterFlush
   	for(int i = 0; i<a ; i++){

   		int bit = bitReaderRead(br);
   		if(lcod>i){ // sigue siendo el cod?? o ya es relleno?
   			HuffmanTreeInfo* nuevo = huffmanTreeInfo(257,0,NULL,NULL);

   			if(bit==0){
   				if(aux->left != NULL){
   					aux=aux->left; //me muevo a izq
   				}else{//creo izq y me muevo
   					aux->left = nuevo;
   					aux = nuevo;
   				}

   			}else{
   				if(aux->right != NULL){
   					aux = aux->right; //me muevo a der
   				}else{//creo der y me muevo
   					aux->right = nuevo;
   					aux = nuevo;
   				}
   			}
   		}
   	}

   	//estoy en pos de hoja
   	aux->c = c;//asigno el char de la hoja
}

void descomprimir(string nomArchCompr)
{
   FILE* f = fopen(nomArchCompr.c_str(),"r+b");

   HuffmanTreeInfo* raiz = huffmanTreeInfo(257,0,NULL,NULL); //raíz del árbol a reconstruir
   HuffmanTreeInfo* aux = huffmanTreeInfo(257,0,NULL,NULL); //auxiliar para recorrer

   int cantHojas = read<unsigned char>(f);
   for(int i = 1; i<=cantHojas ; i++){ //se recorren todas las hojas grabadas
		raiz->n=256+i;
		aux = raiz;

		construirArbol(f,aux); //Construye una rama del árbol hasta la hoja que toca
	}

   unsigned int lonOri = read<unsigned int>(f);//longitud original


   string nombre = nomArchCompr;
   int sLength = length(nombre) - 4; //longitud del nombre sin .huf
   nombre = substring(nombre,0,sLength); // nombre sin .huf
   FILE* reconstruccion = fopen(nombre.c_str(),"w+b"); //archivo reconstruido
   BitReader br = bitReader(f);
   int bit = 0;
   unsigned int i = 0;
   aux=raiz;
   while(i<lonOri){ //recorro el árbol las veces necesarias para reconstruir la longitud original, la i se suma solo cuando llega a una hoja

	   bit=bitReaderRead(br);

	   if(bit==1){//me muevo a la derrecha
		   aux=aux->right;
	   }else if (bit==0){// me muevo a la  izquierda
		   aux=aux->left;
	   }

	   if(aux->left==NULL && aux->right==NULL){
		   //ESTOY EN UNA HOJA
		   write<char>(reconstruccion,aux->c);
		   i++; //un caracter más reconstruído
		   aux=raiz;//vuelvo a la raiz del árbol para seguir recorriendo
	   }
   }


   fclose(reconstruccion);
   fclose(f);
}

int main(int argc, char** argv)
{
   // nombre del archivo con el que voy a trabajar
   string nomArch = argv[1];

   if( !endsWith(nomArch,".huf") ) //comprimo o descomprimo??
   {
      comprimir(nomArch);
   }
   else
   {
      descomprimir(nomArch);
   }

   return 0;
}
#endif
