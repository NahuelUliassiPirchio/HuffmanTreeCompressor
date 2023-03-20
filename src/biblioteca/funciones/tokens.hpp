#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

int tokenCount(string s,char sep) // cuenta los tokens q hay en la cadena
{
   int k = 1;
   int i = 0;

   while (s[i]!='\0')
      {
         if(s[i]==sep)
         {
            k++;
         }

//         if((s[i]==sep) && (s[i+1]==sep))
//         {
//            k--;
//         }

         i++;
      }

//   if(s[0]==sep)
//   {
//      k--;
//   }
//
//   if (s[length(s)-1]==sep)
//   {
//      k--;
//   }

   if (length(s)==0)
   {
      k = 0;
   }

   return k;
}

void addToken(string& s,char sep,string t) // agrega el token "t" al final de la cadena tokenisada
{
   if(length(s)==0)
   {
      s = s + t;
   }
   else
   {
      if(length(s)!=0)
      {
         s = s + sep + t;
      }
   }
}

string getTokenAt(string s,char sep, int pos) // muestra el token de la posicion seleccionada
{
   string k;
   int p = 0;
   int i = 0;
   while(s[i]!='\0')
   {
      while((s[i]!=sep) && (p==pos))
      {
         k = k + s[i];
         i++;
         if(s[i]=='\0')
         {
            i = (length(s)-1);
            p = p * 100;
         }
      }

      if(s[i]==sep)
      {
         p++;
      }

      i++;

   }

   return k;
}

void removeTokenAt(string& s,char sep, int pos) // saca el token de la posicion seleccionada (MUCHOS IF)
{
   string k;
   int p = 0;
   int i = 0;
   int c = 0;
   while(s[i]!='\0')
   {
      while((s[i]!=sep) && (p==pos))
      {
         i++;
         if(s[i]=='\0')
         {
            i = (length(s)-1);
            p = p * 100;
            c = 1;
         }
      }

      if(s[i]==sep)
      {
         p++;
      }

      if(p==pos)
      {

      }
      else
      {
         if(c==1)
         {

         }
         else
         {
            if((p==1) && (s[i]==sep) && (length(k)==0))
            {

            }
            else
            {
               k = k + s[i];
            }
         }
      }
      i++;
   }

   s = k;
}

void setTokenAt(string& s,char sep, string t,int pos) // remplaza el token de la posicion seleccionada por el otro seleccioando
{
   int j = tokenCount(s,sep);
   removeTokenAt(s,sep,pos);
   string k;
   int i = 0;
   int y = 0;
   int h = 0;

   while (s[i]!='\0')
   {
      if(s[i]==sep)
      {
         y++;
      }

      if((y==pos)&&(h==0)&&(y!=0))
      {
         k = k + sep + t;
         h++;
      }
      else
      {
         if((y==pos)&&(h==0))
         {
            k = t + sep + k;
            h++;
         }
      }

      k = k + s[i];
      i++;
   }

   if((y+2==j) && (h==0))
   {
      k = k + sep + t;
      h++;
   }

   s = k;
}

int findToken(string s,char sep, string t) // muestra la posicion del token q se busca
{
   int j = 0;
   int cont = -1;
   int k = 0;

   for (int i=0; s[i]!='\0'; i++)
   {
      while ((s[i]==t[j]) && s[i]!='\0')
      {
         j++;
         i++;
         if (j==length(t))
         {
            cont = i - length(t);
            i = length(s)-1;
         }
      }
   }

   for (int i=0; s[i]!='\0'; i++)
   {
      if ((i<cont)&&(s[i]==sep))
      {
         k++;
      }
   }

   if(cont==-1)
   {
      k = -1;
   }
   return k;
}



#endif
