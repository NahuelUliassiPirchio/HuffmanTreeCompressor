#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include "../funciones/arrays.hpp"

using namespace std;

template<typename T>
struct Array
{
   T* t;
   int len;
   int cap;
};

template<typename T>
Array<T> array(int cap)
{
   Array<T> a;
   a.t = new T[cap];
   a.len = 0;
   a.cap = cap;
   return a;
}

template<typename T>
Array<T> array()
{
   return array<T>(50);
}

template<typename T>
T* arrayGet(Array<T> a,int p)
{
   T* arr = a.t;
   return &arr[p];
}
template<typename T>
void cutNPaste(Array<T>& a){

   int capacidad = a.cap;
   T *newt = new T[capacidad*2];
   T *arr = a.t;

   for(int i = 0; i< a.len;i++){
      newt[i]=arr[i];
   }
   a.cap=capacidad;
   delete a.t;
   a.t=newt;
}

template<typename T>
int arrayAdd(Array<T>& a,T t)//TODO
{
   if(a.len == a.cap){
      cutNPaste<T>(a);
   }
   return add<T>(a.t,a.len,t);
}


template<typename T>
void arraySet(Array<T>& a,int p,T t)
{
   T* element = arrayGet<T>(a,p);
   element->t;
}

template<typename T>
void arrayInsert(Array<T>& a,T t,int p)
{
   if(a.len+1==a.cap)
      cutNPaste<T>(a);
   insert<T>(a.t,a.len,t,p);
}

template<typename T>
int arraySize(Array<T> a)
{
   return a.len;
}

template<typename T>
T arrayRemove(Array<T>& a,int p)
{
   return remove<T>(a.t,a.len,p);
}

template<typename T>
void arrayRemoveAll(Array<T>& a)
{
   delete a.t;
   a.len = 0;
}

template<typename T,typename K>
int arrayFind(Array<T> a,K k,int cmpTK(T,K))
{
   return find<T>(a.t,a.len,k,cmpTK);
}

template<typename T>
int arrayOrderedInsert(Array<T>& a,T t,int cmpTT(T,T))
{
   return orderedInsert(a.t,a.len,t,cmpTT);
}

template<typename T>
void arraySort(Array<T>& a,int cmpTT(T,T))
{
   sort(a.t,a.len,cmpTT);
}

#endif
