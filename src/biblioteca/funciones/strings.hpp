#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int length(string s) // contador de letras (todas)
{
   int i=0;
   while(s[i]!='\0')
   {
      i++;
   }

   return i;
}

int charCount(string s,char x) // contador de letras q esta en el char del main
{
   int cont = 0;
   for (int i=0; s[i]!='\0'; i++)
   {
     if ( s[i] == x)
     {
        cont ++;
     }
   }
   return cont;

}

string substring(string s,int d,int h) // muestra los caracteres q hay entre los numeros seleccionados en el main
{

      string sub2string = "";

      while (d<h)
      {
         char j = s[d];

         sub2string = sub2string + j;

         d++;
      }

   return sub2string;
}

string substring(string s,int d) // muestra los caracteres q hay desde el numero hasta el final (legth)(Tiene el mismo nombre q el de arriba pero como tiene un solo int ya lo cuenta como diferente)
{
      int i = d;

      string sub2string = "";

      while (i<length (s))
      {
         char j = s[i];

         sub2string = sub2string + j;

         i++;
      }

   return sub2string;
}

int indexOf(string s,char e) // muestra la primera posicion del caracter seleccionado en el char del main
{
   int cont = -1;

   for (int t=0; s[t]!='\0'; t++)
   {
     if ( s[t] == e)
     {
        cont = t;
        t = length (s) - 1;
     }
   }
   return cont;
}

int indexOf(string s,char c,int offSet) // muestra la primera posicion del caracter seleccionado en el char del main y a partir de donde contar (offSet)
{
   int cont = -1;

   for (int t = offSet; s[t]!='\0'; t++)
   {
     if ( s[t] == c)
     {
        cont = t;
        t = length (s) -1;
     }
   }
   return cont;
}

int indexOf(string s,string toSearch) // muestra la posicion de donde empieza la palabra q se quiere buscar
{
   int j = 0;
   int cont = -1;

   for (int i=0; s[i]!='\0'; i++)
   {
      while ((s[i]==toSearch[j]) && s[i]!='\0')
      {
         j++;
         i++;
         if (j==length (toSearch))
         {
            cont = i - length (toSearch);
            i = length(s)-1;
         }
      }
   }

   return cont;
}

int indexOf(string s,string toSearch,int offset) // muestra la posicion de donde empieza la palabra q se quiere buscar y a partit de donde contar
{
   int to=0;
   int i=0;
   int pos=-1;
   int g = offset;
   while (s[i]!='\0')
   {
      if (s[i]== toSearch[to] && i>g)
      {
         to=0;
         int impostor=i;
         while (s[i]==toSearch[to])
         {
            i++;
            to++;
            if (toSearch[to]=='\0')
            {
               pos=impostor;
               i--;
            }
         }
      }
      else
      {
         i++;
      }
   }
   return pos;

}

int lastIndexOf(string s,char c) // muestra la ultima posicion del caracter seleccionado en el char del main
{
   int cont = -1;

   for (int t=0; s[t]!='\0'; t++)
   {
     if ( s[t] == c)
     {
        cont = t;
     }
   }
   return cont;
}

int indexOfN(string s,char c,int n) // muestra la n-esima (int n) posicion del caracter seleccionado en el main
{
   int cont = -1;
   int num = 0;

   for (int t=0; s[t]!='\0'; t++)
   {
     if ( s[t] == c)
     {
        cont = t;
        num++;

        if (num==n)
        {
           cont = t;
           t = length (s) - 1;
        }

        if (num!=n) //opcional (devuelve -1 si la n-esima vez no existe)
        {
           cont = -1;
        }

     }
   }
   return cont;
}

int charToInt(char c) // de char (caracter) a int (numero)
{
   int t = c - 48;

   return t;
}

char intToChar(int i) // de int (numero) a char (caracter)
{
   char c = char(i) + 48;

   return c;
}

int getDigit(int n,int i) // muestra el numero en la posicion marcada (de derecha a izquierda)
{
   int t = 1;
   int cont = 0;
   int q = 10;

   while (cont<i)
   {
      q = q * 10;
      t = t * 10;
      cont++;
   }

      n = n % q;
      n = n / t;

   return n;
}

int digitCount(int n) //contador de cifras de un int
{
   int t = 0;
   while (n!=0)
   {
      n = n/10;
      t++;
   }
   return t;
}

string intToString(int p) // pasa de int a string
{
   string s;

   char c;
   int u;
   int nuevo = p;
   while (length(s)!=digitCount(p))
   {
      int cont = 1;
      int t = 1;
      while (cont<digitCount(nuevo))
         {
            t = t*10;
            cont++;
         }
      u = nuevo / t;
      c = char(u) + 48;
      s = s + c;
      nuevo = nuevo % t;
   }

   return s;
}

int stringToInt(int s,int b) // NO LO ENTENDI
{
   return 0;
}

int stringToInt(string s) // pasa de string a int
{
   int k = 0;
   int i = 0;
   int y = 0;
   int u;
   while(s[i]!='\0')
   {
      int l = 1;
      int r = 1;
      while(l<(length(s)-y))
      {
         r = r * 10;
         l++;
      }
      u = (s[i]-48) * r;
      k = k + u;
      i++;
      y++;
   }
   return k;
}

string charToString(char c) // pasa de char a string
{
   string k;

   k = k + c;

   return k;
}

char stringToChar(string s) // pasa de string (longitud 1) a char
{
   char c = s[0];

   return c;
}

string stringToString(string s) // pasa de string a string
{
   string k = s;
   return k;
}

string doubleToString(double d)
{
   string s;

   return s;
}

double stringToDouble(string s)
{
   return 1;
}

bool isEmpty(string s) // indica si el string esta vacio o no
{
   bool bul = false;
   int i=0;
   while(s[i]!='\0')
   {
      i++;
   }
   if (i==0)
   {
      bul = true;
   }

   return bul;
}

bool startsWith(string s,string x) // indica si empieza con la palabra seleccionada o no
{
   bool ok = false;
   int j = 0;
   int cont = -1;

   for (int i=0; s[i]!='\0'; i++)
   {
      while ((s[i]==x[j]) && s[i]!='\0')
      {
         j++;
         i++;
         if (j==length (x))
         {
            cont = i - length (x);
         }
      }
   }
   if (cont == 0)
   {
      ok = true;
   }
   return ok;
}

bool endsWith(string s,string x) // NOSE PORQ NO FUNCA PERO PARA MI ESTA BIEN!!
{
   bool ok = false;
   int j = 0;
   int cont = -1;

   for (int i=0; s[i]!='\0'; i++)
   {
      while ((s[i]==x[j]) && s[i]!='\0')
      {
         j++;
         i++;
         if (j==length (x))
         {
            cont = i - length (x);
         }
      }
   }

   int p = cont+length(x);

   if (p == length (s))
   {
      ok = true;
   }

   return ok;
}

bool contains(string s,char c) // indica si contiene al caracter seleccionado
{
   int cont = -1;
   bool ok = false;

   for (int t=0; s[t]!='\0'; t++)
   {
     if ( s[t] == c)
     {
        cont = t;
        t = length (s) - 1;
     }
   }

   if (cont!=-1)
   {
      ok = true;
   }

   return ok;
}

string replace(string s,char oldChar,char newChar) // remplaza un caracter por otro en un string
{
   int i=0;
   while(s[i]!='\0')
   {
      if (s[i]==oldChar)
      {
         s[i] = newChar;
      }

      i++;
   }

   return s;
}

string insertAt(string s,int pos,char c) // inserta el caracter seleccionado en el lugar seleccionado
{
   string k;
   int i=0;
   while(s[i]!='\0')
   {
      if (i==pos)
      {
         k = k + c;
      }

      k = k + s[i];
      i++;
   }

   return k;
}

string removeAt(string s,int pos) // remueve el caracter de la posicion seleccionada
{
   string k;
   int i=0;
   while(s[i]!='\0')
   {
      if (i==pos)
      {
         i++;
      }
      else
      {
         k = k + s[i];
         i++;
      }
   }

   return k;
}

string ltrim(string s) // saca los espacios al principio del string
{
   string k;
   int i=0;
   while(s[i]!='\0')
   {
      while ((s[i]==' ') && (length(k) == 0))
      {
         i++;
      }

         k = k + s[i];
         i++;
   }

   return k;
}

string rtrim(string s) // saca los espacios al final del string
{
   string k;
   int i=0;
   int p = length(s);
   while(s[p-1]==' ')
   {
      p--;
   }
   while(i<p)
   {
      k = k + s[i];
      i++;
   }

   return k;
}

string trim(string s) // saca los espacios al principio y al final del string
{
   string k;
   int i = 0;
   int q = 0;
   int p = length(s);
   while(s[p-1]==' ')
   {
      p--;
   }
   while(q<p)
   {
      while ((s[i]==' ') && (length(k) == 0))
      {
         i++;
         q++;
      }

      k = k + s[i];
      i++;
      q++;
   }


   return k;
}

string replicate(char c,int n) // agrega la cantidad del caracter indicado
{
   string s;
   int i = length(s);

   while(i<n)
   {
      s = s + c;
      i++;
   }

   return s;
}

string spaces(int n) // agrega la cantidad de espacios seleccionados
{
   int t = 0;
   string s;
   string p = " ";
   while (n>t)
   {
      s = s + p;
      t++;
   }
   return s;
}

string lpad(string s,int n,char c) // añade el caracteres selecionado (Al principio) para q llegue a la longitud pedida
{
   int q = n-length(s);
   while (q!=0)
   {
      s = c + s;
      q--;
   }

   return s;
}

string rpad(string s,int n,char c) // añade el caracteres selecionado (Al final) para q llegue a la longitud pedida
{
   int q = n-length(s);
   while (q!=0)
   {
      s = s + c;
      q--;
   }

   return s;
}

string cpad(string s,int n,char c) // añade el caracteres selecionado (Distribuido) para q llegue a la longitud pedida
{
   int q = n-length(s);
   int cont = 0;
   while (q!=0)
   {
      if (cont == 0)
      {
         s = c + s;
         q--;
         cont ++;
      }
      else
      {
         if (cont == 1)
         {
            s = s + c;
            q--;
            cont--;
         }
      }
   }

   return s;
}

bool isDigit(char c) // indica si el caracter es un digito o no
{
   return (c >= 48 && c <=57);
}

bool isLetter(char c) // indica si el caracter es una letra o no
{
   return (c <48 || c >57);
}

bool isUpperCase(char c) // indica si el caracter es una letra mayuscula o no
{
   return (c >= 65 && c <=90);
}

bool isLowerCase(char c) // indica si el caracter es una letra minuscula o no
{
   return (c >= 97 && c <=122);
}

char toUpperCase(char c) // pasa de minuscula a mayuscula (caracter)
{
   if (isLowerCase(c))
   {
      c = c - 32;
   }

   return c;
}

char toLowerCase(char c) // pasa de mayuscula a minuscula (caracter)
{
   if (isUpperCase(c))
   {
      c = c + 32;
   }

   return c;
}

string toUpperCase(string s) // pasa de minuscula a mayuscula (string)
{
   string k;
   int i = 0;

   while(s[i]!='\0')
   {
      char c = s[i];
      if((s[i]>= 97) && (s[i] <=122))
      {
         c = c - 32;
      }

      k = k + c;
      i++;
   }

   return k;
}

string toLowerCase(string s) // pasa de mayuscula a minuscula (string)
{
   string k;
   int i = 0;

   while(s[i]!='\0')
   {
      char c = s[i];
      if((s[i]>= 65) && (s[i] <=90))
      {
         c = c + 32;
      }

      k = k + c;
      i++;
   }

   return k;
}

#endif
