#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

int main()
{
    int m = 0;
    int n = 0;
    cin >> n >> m;
    node* head = new node;
    node* rear = head;
    node* prev = NULL;
    for (int i = 0; i < n; i++) {
        rear->data = i + 1;
        node* p = new node;
        prev = rear;
        rear->next = p;
        rear = p;
    }
    rear = prev;
    rear->next = head;
    while (head->next != head) {
        for (int i = 0; i < m - 1; i++) {
            prev = head;
            head = head->next;
        }
        prev->next = head->next;
        head = head->next;
    }

    cout << head->data << endl;

    return 0;
}
