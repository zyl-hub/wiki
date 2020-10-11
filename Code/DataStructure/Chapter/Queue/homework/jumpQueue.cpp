#include <iostream>
using namespace std;

struct node {
    int data = 0;
    int order = -1;
    node* next = NULL;
};

void jumpQueue(node*& head, int order, int* team);

void pop(node*& head);

int main()
{
    node* head = new node;
    int order = 1;
    int n = 0;
    cin >> n;
    int* team = new int[n];
    for (int i = 0; i < n; i++) {
        int tempData = 0;
        cin >> tempData;
        team[i] = tempData;
    }
    int operationNumber = 0;
    cin >> operationNumber;
    for (int i = 0; i < operationNumber; i++) {
        int tempOperation = 0;
        cin >> tempOperation;
        if (tempOperation == 0) {
            if (order <= n) {
                if (head->data == 0) {
                    head->order = order;
                    head->data = team[order - 1];
                    order += 1;
                } else {
                    jumpQueue(head, order, team);
                    order += 1;
                }
            }
        }
        if (tempOperation == 1) {
            pop(head);
        }
    }

    return 0;
}

void jumpQueue(node*& head, int order, int* team)
{
    node* tempHead = head;
    node* prevHead = head;

    while (tempHead->data != team[order - 1] && tempHead->next != NULL) {
        prevHead = tempHead;
        tempHead = tempHead->next;
    }
    while (tempHead->data == team[order - 1] && tempHead->next != NULL) {
        prevHead = tempHead;
        tempHead = tempHead->next;
    }
    if (tempHead->data == team[order - 1] && tempHead->next == NULL) {
        prevHead = tempHead;
    }
    if (prevHead->data != team[order - 1] && tempHead->data != team[order - 1] && tempHead->next == NULL) {
        prevHead = tempHead;
    }
    node* temp = new node;
    node* tempNode = new node;
    temp->data = team[order - 1];
    temp->order = order;
    tempNode = prevHead->next;
    prevHead->next = temp;
    temp->next = tempNode;
}

void pop(node*& head)
{
    if (head->next == NULL && head->order != -1) {
        cout << head->order << endl;
        head->order = -1;
        head->data = 0;
        return;
    }
    if (head->order == -1) {
        cout << head->order << endl;
        return;
    }
    cout << head->order << endl;
    head = head->next;
}
