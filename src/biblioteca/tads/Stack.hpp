#ifndef _TSTACK_TAD_
#define _TSTACK_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct Stack
{
	Node<T>* t;

};

template<typename T>
Stack<T> stack()
{
   Stack<T> st;
   st.t = NULL;
   return st;
}

template<typename T>
T* stackPush(Stack<T>& st,T e)
{
	Node<T>* n = addFirst<T>(st.t,e);
	T* t = &(n->val);
   return t;
}

template<typename T>
T stackPop(Stack<T>& st)
{
   return removeFirst<T>(st.t);
}

template<typename T>
bool stackIsEmpty(Stack<T> st)
{
   return st.t==NULL;
}

template<typename T>
int stackSize(Stack<T> st)
{
   return size<T>(st.t);
}

#endif
