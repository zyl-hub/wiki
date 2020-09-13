#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int d = 0, Node* n = NULL)
  {
    data = d;
    next = n;
  }
};

int main()
{
  Node *head, *p, *q;

  // 创建链表
  head = new Node();
  p = head->next = new Node(3);
  //p = new Node(3);

  p->next = new Node(4);
  //p = new Node(4);

  // 输出链表
  p = head;
  while (p != NULL) {
    cout << p->data << " ";
    p = p->next;
  }

  // 删除链表
  while (head != NULL) {
    q = head->next;
    delete head;
    head = q;
  }

  return 0;
}
