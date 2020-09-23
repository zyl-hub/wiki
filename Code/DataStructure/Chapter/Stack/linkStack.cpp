#include "stack.h"
#include <iostream>
using namespace std;

template <class T>
linkStack<T>::linkStack()
{
    top_p = NULL;
}

template <class T>
linkStack<T>::~linkStack()
{
    node* tmp;
    while (top_p != NULL) {
        tmp = top_p;
        top_p = top_p->next;
        delete tmp;
    }
}

template <class T>
bool linkStack<T>::isEmpty() const
{
    return top_p == NULL;
}

template <class T>
void linkStack<T>::push(const T& x)
{
    top_p = new node(x, top_p);
}

template <class T>
T linkStack<T>::pop()
{
    node* tmp = top_p;
    T x = tmp->data;
    top_p = top_p->next;
    delete tmp;
    return x;
}
