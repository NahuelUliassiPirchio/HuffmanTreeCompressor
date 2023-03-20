#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

template <typename T>
int add(T arr[],int& len,T e)
{
   arr [len] = e;
   len++;

   return len-1;
}

template <typename T>
void insert(T arr[],int& len,T e,int p)
{
   for(int i=len; i>p; i--)
   {
       arr[i]=arr[i-1];
   }
   arr[p]=e;
   len++;
}

template <typename T>
T remove(T arr[],int& len,int p)
{
   T ret;
   ret=arr[p];
   for(int i=p; i<len;i++)
   {
       arr[i]=arr[i+1];
   }
   len--;

   return ret;
}

template <typename T, typename K>
int find(T arr[],int len,K k,int cmpTK(T,K))
{
   int pos = -1;
   for(int i=0; i<len; i++)
   {
       if ( cmpTK(arr[i], k) == 0 )
       {
           pos=i;
           i = len;
       }
   }
   return pos;
}

template <typename T>
int orderedInsert(T arr[],int& len,T e,int cmpTT(T,T))
{
   int i;
   bool b = false;
   for( i =0; !b ;i++){
      if(cmpTT(arr[i],e)>0){
         insert<T>(arr,len,e,i);
         b = true;
      }
   }
   return i;
}

template <typename T>
void sort(T arr[],int len,int cmpTT(T,T))
{
   for (int i=0;i<len;i++)
     {
        for (int j=0;j<len-1;j++)
        {
           if (cmpTT(arr[j],arr[j+1])>0)
           {
              T aux = arr[j];
              arr[j]=arr[j+1];
              arr[j+1]=aux;
           }
        }
     }
}

#endif
