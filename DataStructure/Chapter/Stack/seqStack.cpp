#include "stack.h"
template <class T>
seqStack<T>::seqStack(int initSize)
{
  elem = new T[initSize];
  maxSize = initSize;
  top_p = -1;
}

template <class T>
seqStack<T>::~seqStack()
{
  delete[] elem;
}

template <class T>
bool seqStack<T>::isEmpty() const
{
  return top_p == -1;
}

template <class T>
void seqStack<T>::push(const T& x)
{
  if (top_p == maxSize - 1)
    doubleSpace();
  elem[++top_p] = x;
}

template <class T>
T seqStack<T>::pop()
{
  return elem[top_p--];
}

template <class T>
T seqStack<T>::top() const
{
  return elem[top_p];
}

template <class T>
void seqStack<T>::doubleSpace()
{
  T* tmp = elem;

  elem = new T[2 * maxSize];

  for (int i = 0; i < maxSize; ++i) {
    elem[i] = tmp[i];
    maxSize *= 2;
    delete[] tmp;
  }
}
