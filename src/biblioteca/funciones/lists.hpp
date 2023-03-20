#ifndef _TLIST_T_
#define _TLIST_T_

#include <iostream>
#include <stdio.h>

template <typename T>
struct Node
{
   T val;
   Node<T>* sig;
};

/*template<typename T>
void show(Node<T>* p){
   Node<T>* aux = p;
   while(aux!=NULL){
      cout<<aux->val<<endl;
      aux = aux->sig;
   }
}*/

template<typename T>
int size(Node<T>*& p){
   Node<T>* aux = p;
   int c = 0;
   while(aux!=NULL){
      aux = aux->sig;
      c++;
   }
   return c;
}

template <typename T>
Node<T>* add(Node<T>*& p,T e)
{
   Node<T>* nuevo = new Node<T>();
   nuevo->val = e;
   nuevo->sig = NULL;
   if(p!=NULL){
      Node<T>* aux = p;
      while(aux->sig!=NULL){
         aux = aux->sig;
      }
      aux->sig = nuevo;
   }else{
      p = nuevo;
   }
   return nuevo;
}

template <typename T>
Node<T>* addFirst(Node<T>*& p,T e)
{
   Node<T>* nuevo = new Node<T>();
   if(p!=NULL){
      nuevo->sig = p->sig;
      nuevo->val = p->val;
      p->sig = nuevo; //p=nuevo
      p->val = e;
   }else{
      nuevo->val=e;
      p = nuevo;
   }
   return nuevo;
}

template <typename T, typename K>
T remove(Node<T>*& p,K k,int cmpTK(T,K)) //TODO
{
   Node<T>* aux = p;
   Node<T>* ant;
   T val;
   bool f = false;

   while(!f){

      if(cmpTK(aux->val,k)==0){
        val = aux->val;
        ant->sig = aux->sig;
        f = true;
      }else{
        ant = aux;
        aux = aux->sig;
      }
   }

   return val;
}

template <typename T>
T removeFirst(Node<T>*& p) //TODO:si es null, si no anda esta en el libro p227
{
   T t;
   if(p!=NULL && p->sig != NULL){
      Node<T>* second = p->sig;
      t = p->val;
      p->val=second->val;
      p->sig=second->sig;
      delete second;
   }else if (p!=NULL && p->sig == NULL){
      t = p->val;
      p = NULL;
   }else{

   }
   return t;
}

template <typename T, typename K>
Node<T>* find(Node<T>* p,K k,int cmpTK(T,K))//TODO
{
      Node<T>* aux = p;

      while(aux!=NULL && cmpTK(aux->val,k)!=0){
         aux = aux->sig;
      }

      return aux;
}

template <typename T>
Node<T>* orderedInsert(Node<T>*& p,T e,int cmpTT(T,T))//TODO
{
	Node<T>* nuevo = new Node<T>();
	if(p!=NULL){
		Node<T>* aux = p;
		nuevo->val = e;
		nuevo->sig = NULL;

		if(cmpTT(aux->val,nuevo->val)<=0){
			addFirst<T>(p,e);
		}else{
			while(aux->sig!=NULL && cmpTT(aux->sig->val,nuevo->val)>0){
				aux=aux->sig;
			}

			nuevo->sig=aux->sig;
			aux->sig=nuevo;
		}

	}else{
		nuevo = addFirst<T>(p,e);
	}
	return nuevo;
}

template <typename T>
Node<T>* searchAndInsert(Node<T>*& p,T e,bool& enc,int cmpTT(T,T))//TODO
{
   return NULL;
}

template <typename T>
void sort(Node<T>*& p,int cmpTT(T,T))//TODO
{
	Node<T> * cur1 = p;
	Node<T>* cur2 = p;

	for(int i = 0; i<size<T>(p);i++){
		for(int j = 0; j<size<T>(p)-1;j++){
			if(cmpTT(cur1->val,cur2->val)>0){
				T temp = cur1->val;
				cur1->val=cur2->val;
				cur2->val=temp;
			}
			cur2 = cur2->sig;
		}
		cur2 = p;
		cur1 = p->sig;
		for(int k = 0 ; k<i;k++){
			cur1 = cur1->sig;
		}
	}
}

template <typename T>
bool isEmpty(Node<T>* p)
{
   return p==NULL;
}

template <typename T>
void free(Node<T>*& p)
{
   while (p!=NULL){
      Node<T>* sig = p->sig;
      delete p;
      p = sig;
   }
}

template <typename T>
Node<T>* push(Node<T>*& p,T e)
{
   return addFirst<T>(p,e);
}

template <typename T>
T pop(Node<T>*& p)
{
   return removeFirst<T>(p);
}

template <typename T>
Node<T>* enqueue(Node<T>*& p,Node<T>*& q,T e)//TODO 211
{
   Node<T>* t = new Node<T>();
   t->val = e;
   t->sig = NULL;

   if( q!=NULL ){
      q->sig = t;
   }else{
      p = t;
   }

   q = t;

   return t;
}

template <typename T>
Node<T>* enqueue(Node<T>*& q,T e)
{
   return add<T>(q,e);
}

template <typename T>
T dequeue(Node<T>*& p, Node<T>*& q)
{
   T t = p->val;
   Node<T>* aux = p;
   p = p->sig;
   delete aux;
   if( p==NULL ){
      q = NULL;
   }
   return t;
}

template <typename T>
T dequeue(Node<T>*& q)//TODO
{
   return removeFirst<T>(q);
}


#endif
