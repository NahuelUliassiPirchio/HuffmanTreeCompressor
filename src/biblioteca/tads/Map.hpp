
#ifndef _TMAP_TAD_
#define _TMAP_TAD_

#include <iostream>
#include "Array.hpp"

using namespace std;

template<typename K,typename T>
struct Map
{
   Array<K> keys;
   Array<T> val;
   int pos;
};

template<typename K,typename V>
Map<K,V> map()
{
   Map<K,V> m;
   m.keys = array<K>();
   m.val = array<V>();
   m.pos = -1;
   return m;
}

template<typename K>
int cmpKK(K k1,K k2){
   return k1-k2;
}

template<typename K,typename V>
V* mapGet(Map<K,V> m,K k)
{
   int pos = arrayFind<K>(m.keys,k,cmpKK);
   return pos>=0 ? arrayGet<V>(m.val,pos) : NULL;
}

template<typename K,typename V>
V* mapPut(Map<K,V>& m,K k,V v)
{
   V* w = mapGet<K,V>(m,k);
   if (w!=NULL){
      *w = v;
   }else{
      int pos = arrayAdd<K>(m.keys,k);
      arrayAdd<V>(m.val,v);
      w = arrayGet<V>(m.val,pos);
   }
   return w;
}

template<typename K,typename V>
bool mapContains(Map<K,V> m,K k)
{
   V* w = mapGet<K,V>(m,k);
   return w!=NULL;
}

template<typename K,typename V>
V mapRemove(Map<K,V>& m,K k)
{
   int pos = arrayFind<K>(m.keys,k,cmpKK);
   arrayRemove<K>(m.keys,pos);
   V v = arrayRemove<V>(m.val,pos);;
   return v;
}

template<typename K,typename V>
void mapRemoveAll(Map<K,V>& m)
{
   arrayRemoveAll<K>(m.keys);
   arrayRemoveAll<V>(m.val);
   m.pos = 0;
}

template<typename K,typename V>
int mapSize(Map<K,V> m)
{
   return arraySize(m.keys);
}

template<typename K,typename V>
bool mapHasNext(Map<K,V> m)
{
   int size = arraySize<K>(m.keys);
   return m.pos < size-1;
}

template<typename K,typename V>
K mapNextKey(Map<K,V>& m)
{
   m.pos++;
   return *arrayGet<K>(m.keys,m.pos);
}

template<typename K,typename V>
V* mapNextValue(Map<K,V>& m)
{
   m.pos++;
   return arrayGet<V>(m.val,m.pos);
}

template<typename K,typename V>
void mapReset(Map<K,V>& m)
{
   m.pos = -1;
}

template<typename K,typename V>
void mapSortByKeys(Map<K,V>& m,int cmpKK(K,K))//TODO
{
}

template<typename K,typename V>
void mapSortByValues(Map<K,V>& m,int cmpVV(V,V))//TODO
{
}

#endif
