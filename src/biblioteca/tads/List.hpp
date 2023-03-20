#ifndef _TLIST_TAD_
#define _TLIST_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct List
{
   Node<T>* t;
   int pos;
};

template<typename T>
List<T> list()
{
   List<T> lst;
   lst.t=NULL;
   lst.pos = -1;
   return lst;
}

template<typename T>
T* listAdd(List<T>& lst,T e)
{
   Node<T>* n = add<T>(lst.t,e);
   return &(n->val);
}

template<typename T>
T* listAddFirst(List<T>& lst,T e)
{
	Node<T>* n = addFirst<T>(lst.t,e);
	   return &(n->val);
}

template<typename T,typename K>
T listRemove(List<T>& lst,K k,int cmpTK(T,K))
{
   return remove<T>(lst.t,k,cmpTK);
}

template<typename T>
T listRemoveFirst(List<T>& lst)
{
   return removeFirst<T>(lst.t);
}

template<typename T,typename K>
T* listFind(List<T> lst,K k,int cmpTK(T,K))
{
   return NULL;
}

template<typename T>
bool listIsEmpty(List<T> lst)
{
   return lst.t==NULL;
}

template<typename T>
int listSize(List<T> lst)
{
   return size<T>(lst.t);
}

template<typename T>
void listFree(List<T>& lst)
{
   free<T>(lst.t);
}

template<typename T>
T* listOrderedInsert(List<T>& lst,T t,int cmpTT(T,T))
{
	Node<T>* f = orderedInsert<T>(lst.t,t,cmpTT);
   return &(f->val);
}

template<typename T>
void listSort(List<T>& lst,int cmpTT(T,T))
{
	sort<T>(lst.t,cmpTT);
}

template<typename T>
void listReset(List<T>& lst)
{
   lst.pos=-1;
}

template<typename T>
bool listHasNext(List<T> lst)
{
   int size = listSize<T>(lst);
   return lst.pos < size-1;;
}

template<typename T>
T* listNext(List<T>& lst)
{
   return NULL;
}

template<typename T>
T* listNext(List<T>& lst,bool& endOfList)
{
   T* t;
   return t;
}

#endif
