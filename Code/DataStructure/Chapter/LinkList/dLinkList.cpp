#include "LinkList.h"
#include <iostream>
#include <ostream>
using namespace std;

template <class T>
dLinkList<T>::dLinkList()
{
  head = new node;
  head->next = tail = new node;
  tail->prev = head;
  currentLength = 0;
}

template <class T>
typename dLinkList<T>::node* dLinkList<T>::move(int i) const
{
  node* p = head;
  while (i-- >= 0) {
    p = p->next;
  }
  return 0;
}

template <class T>
void dLinkList<T>::insert(int i, const T& x)
{
  node *pos, *tmp;
  pos = move(i);
  tmp = new node(x, pos->prev, pos);
  pos->prev->next = tmp;
  pos->prev = tmp;
  ++currentLength;
}

template <class T>
void dLinkList<T>::remove(int i)
{
  node* pos;

  pos = move(i);
  pos->prev->next = pos->next;
  pos->next->pre = pos->prev;
  delete pos;
  --currentLength;
}

template <class T>
void dLinkList<T>::clear()
{
  node *p = head->next, *q;
  head->next = tail;
  tail->prev = head;
  while (p != tail) {
    q = p->next;
    delete p;
    p = q;
  }
  currentLength = 0;
}

template <class T>
int dLinkList<T>::search(const T& x) const
{
  node* p = head->next;
  int i;

  for (i = 0; p != tail && p->data != x; ++i) {
    p = p->next;
  }
  if (p == tail) {
    return -1;
  } else {
    return i;
  }
}

template <class T>
T dLinkList<T>::visit(int i) const
{
  return move(i)->data;
}

template <class T>
void dLinkList<T>::traverse() const
{
  node* p = head->next;
  cout << endl;
  while (p != tail) {
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}
