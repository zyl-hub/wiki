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
  Node *head, p, q;

  // ��������
  head = new Node();
  p = head->next;
  p = new Node(3);
  q = p->next;
  p = new Node(4);

  // �������
  p = head;
  while (p != NULL) {
    cout << p->data << " ";
    p = p->next;
  }

  // ɾ������
  while (head != NULL) {
    delete head;
    head = head->next;
  }

  return 0;
}
