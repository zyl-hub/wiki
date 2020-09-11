
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
void sLinkList<T>::remove(int i)
{
  node *pos, *delp;

  pos = move(i - 1);
  delp = pos->next;
  pos->next = delp->next;
  delete delp;
  --currentLength;
}
