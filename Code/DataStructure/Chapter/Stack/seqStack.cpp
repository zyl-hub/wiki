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
