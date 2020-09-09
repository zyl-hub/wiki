#include "LinkList.h"
#include <iostream>

template <class T>
class dLinkList : public list<T> {
  private:
  struct node {
    T data;
    node *prev, *next;

    node(const T& x, node* p = 0, node* n = 0)
    {
      data = x;
      next = n;
      prev = p;
    }
    node()
        : next(0)
        , prev(0)
    {
    }
    ~node() { }
  };
}
