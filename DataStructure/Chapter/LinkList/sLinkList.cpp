#include "LinkList.h"
#include <cstdio>
#include <iostream>

template <class T>
typename sLinkList<T>::node* sLinkList<T>::move(int i) const
{
  node* p = head;
  while (i-- >= 0) {
    p = p->next;
  }
  return p;
}

template <class T>
sLinkList<T>::sLinkList()
{
  head = new node;
  currentLength = 0;
}

template <class T>
void sLinkList<T>::clear()
{
  node *p = head->next, *q;
  head->next = 0;
  while (p != 0) {
    q = p->next;
    delete p;
    p = q;
  }
  currentLength = 0;
}

template <class T>
void sLinkList<T>::insert(int i, const T& x)
{
  node* pos;

  pos = move(i - 1);
  pos->next = new node(x, pos->next);
  ++currentLength;
}

template <class T>
void sLinkList<T>::remove(int i)
{
  node *pos, *delp;

  pos = move(i - 1);
  delp = pos->next;
  pos->next = delp->next;
  delete delp;
  --currentLength;
}

template <class T>
int sLinkList<T>::search(const T& x) const
{
  node* p = head->next;
  int i = 0;

  while (p != 0 && p->data != x) {
    p = p->next;
    ++i;
  }
  if (p == 0)
    return -1;
  else {
    return i;
  }
}

template <class T>
T sLinkList<T>::visit(int i) const
{
  return move(i)->data;
}

template <class T>
void sLinkList<T>::traverse() const
{
  node* p = head->next;
  std::cout << std::endl;
  while (p != 0) {
    std::cout << p->data << '\t';
    p = p->next;
  }
  std::cout << std::endl;
}

template <class T>
void sLinkList<T>::erase(int i)
{
  node *pre = move(i - 1), *delp = pre->next;
  T tmp = delp->data;
  int cnt = 1;

  pre->next = delp->next;
  delete delp;

  for (pre = head; pre->next != 0;) {
    if (pre->next->data == tmp) {
      delp = pre->next;
      pre->next = delp->next;
      delete delp;
      ++cnt;
    } else
      pre = pre->next;
    currentLength -= cnt;
  }
}

//no tested
template <class T>
void sLinkList<T>::erase(T x, T y)
{
  node *prev = head, *temp = head, *q;
  while (temp != 0) {
    if (temp->data >= x && temp->data <= y) {
      prev = temp;
      q = temp->next;
      prev->next = q->next;
      delete temp;
      temp = q;
    }
    else {
    prev = temp;
    q = temp->next;
    prev->next = q->next;
    temp = q;
    }
  }
}
