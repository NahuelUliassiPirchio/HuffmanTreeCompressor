#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../funciones/strings.hpp"
#include "../funciones/tokens.hpp"

using namespace std;

template<typename T>
struct Coll
{
   string s;
   char sep;
   int pos;
};

template<typename T>
Coll<T> coll(char sep)
{
   Coll<T> c;
   c.s = "";
   c.sep = '|';
   c.pos = 0;
   return c;
}

template<typename T>
Coll<T> coll()
{
   Coll<T> c;
   c.s = "";
   c.sep = '|';
   c.pos = 0;
   return c;
}

template<typename T>
int collSize(Coll<T> c) // Retorna la cantidad de elementos que contiene la colección C
{
   //int n = collSize(c);
   int k = tokenCount(c.s,c.sep);
   return k;
}

template<typename T>
void collRemoveAll(Coll<T>& c) // Remueve de la colección C todos sus elementos, dejándola vacía
{
   //collRemoveAll(c);
   c.s = "";
}

template<typename T>
void collRemoveAt(Coll<T>& c, int p) // Remueve de la colección C el elemento ubicado en la posición P
{
   //collRemoveAt(c,2);
   removeTokenAt(c.s,c.sep,p);
}

template<typename T>
int collAdd(Coll<T>& c,T t,string tToString(T)) // Agrega el elemento T al final de la colección C
{
   //Coll<string> c = coll<string>();
   //collAdd<string>(c,"Pablo",stringToString);
   int q = tokenCount(c.s,c.sep);
   addToken(c.s,c.sep,tToString(t));
   return q;
}

template <typename T>
void collSetAt(Coll<T>& c,T t,int p,string tToString(T)) // Reemplaza por t al elemento que se ubica en la posición p.
{
   //collSetAt<string>(c,"Enru",2,stringToString);
   setTokenAt(c.s,c.sep,tToString(t),p);
}

template <typename T>
T collGetAt(Coll<T> c,int p,T tFromString(string)) // Retorna el elemento que se ubica en la posición p de la colección c.
{
   //string n = collGetAt<string>(c,1,stringToString);
   //int n = collGetAt<int>(c,1,stringToInt);
   T t = tFromString(getTokenAt(c.s,c.sep,p));
   return t;
}

template <typename T, typename K>
int collFind(Coll<T> c,K k,int cmpTK(T,K),T tFromString(string)) // Determina si la colección c contiene al elemento k.
{
   //int n = collFind<string,string>(c,"Yo",cmpString,stringToString);
   //int n = collFind<int,int>(c,4,cmpInt,stringToInt);
   int pos = -1;
   for (int i=0;i<collSize<T>(c);i++)
   {
      if(cmpTK(collGetAt<T>(c,i,tFromString),k)==0)
      {
         pos = i;
         i = collSize<T>(c)-1;
      }
   }
   return pos;
}

template <typename T>
void collSwap(Coll<T>& c, int p1, int p2)
{
   string t1 = getTokenAt(c.s, c.sep, p1);
   setTokenAt(c.s, c.sep, getTokenAt(c.s, c.sep, p2), p1);
   setTokenAt(c.s, c.sep, t1, p2);
}

//no usa el parametro: string tToString(T), pero necesita de la funcion collSwap para permutar directamente los tokens

template<typename T>
void collSort(Coll<T> &c, int cmpTT(T, T), T tFromString(string), string tToString(T)) //Ordena los elementos de la colección c según el criterio de precedencia que establece cmpTT.
{
   //collSort<int>(c,cmpInt,stringToInt,intToString);
   for (int i=0;i<collSize<T>(c);i++)
   {
      for (int j=0;j<collSize<T>(c)-1;j++)
      {
         if (cmpTT(collGetAt<T>(c,j,tFromString),collGetAt<T>(c,j+1,tFromString))>0)
         {
            collSwap<T>(c, j, j + 1);
         }
      }
   }
}

template<typename T>
bool collHasNext(Coll<T> c) // Retorna true o false según queden, en la colección c, más elementos para continuar iterando.
{
   return collSize<T>(c)>c.pos;
}

template<typename T>
T collNext(Coll<T>& c,T tFromString(string)) // Retorna el próximo elemento de la colección c.
{
   //string s = collNext<string>(c,stringToString);
   T t;
   t = collGetAt<T>(c,c.pos,tFromString);
   c.pos++;

   return t;
}

template<typename T>
void collReset(Coll<T>& c) // Reinicia la colección c para que la podamos volver a iterar.
{
   //collReset<string>(c);
   c.pos=0;
}


template<typename T>
string collToString(Coll<T> c)
{
   return c.sep+c.s;
}

template<typename T>
Coll<T> collFromString(string s)
{
   Coll<T> c;
   c.sep=s[0];
   c.s=substring(s,1);
   return c;
}


#endif
