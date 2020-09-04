#include "LinkList.h"
#include <iostream>
using namespace std;
template <class T>
seqList<T>::~seqList() { delete[] data; }

template <class T>
void seqList<T>::clear() { currentLength = 0; }

template <class T>
int seqList<T>::length() const { return currentLength; }

template <class T>
T seqList<T>::visit(int i) const { return data[i]; }

template <class T>
void seqList<T>::traverse() const
{
  cout << endl;
  for (int i = 0; i < currentLength; ++i)
    cout << data[i] << ' ';
}

template <class T>
seqList<T>::seqList(int initSize)
{
  data = new T[initSize];
  maxSize = initSize;
  currentLength = 0;
}

template <class T>
int seqList<T>::search(const T& x) const
{
  for (int i = 0; i < currentLength && data[i] != x; ++i)
    if (i == currentLength)
      return -1;
    else
      return i;
}

template <class T>
void seqList<T>::doubleSpace()
{
  T* tmp = data;

  maxSize *= 2;
  data = new T[maxSize];
  for (int i = 0; i < currentLength; ++i)
    data[i] = tmp[i];
  delete[] tmp;
}

template <class T>
void seqList<T>::insert(int i, const T& x)
{
  if (currentLength == maxSize)
    doubleSpace();
  for (int j = currentLength; j > i; j--)
    data[j] = data[j - 1];
  data[i] = x;
  ++currentLength;
}

template <class T>
void seqList<T>::remove(int i)
{
  for (int j = i; j < currentLength - 1; j++)
    data[j] = data[j + 1];
  --currentLength;
}
