#include <iostream>
using namespace std;

struct node {
    int priority = 0;
    int isPrint = 0;
    node* next;
};

void enQueue(node*& rear, int tempPriority);

void moveToRear(node*& head, node*& rear, int pos);

void priorityPrinting(node*& head, int pos);

int main()
{
    node* head = new node;
    node* rear = new node;
    int testDataSetNumber = 0;
    cin >> testDataSetNumber;
    for (int i = 0; i < testDataSetNumber; i++) {
        int length = 0;
        int pos = 0;
        cin >> length;
        cin >> pos;
        for (int k = 0; k < length; k++) {
            int tempPriority = 0;
            cin >> tempPriority;
            enQueue(rear, tempPriority);
        }
    }
    return 0;
}

void enQueue(node*& rear, int tempPriority)
{
    node* temp = new node;
    temp->priority = tempPriority;
    rear->next = temp;
    rear = temp;
}

void moveToRear(node*& head, node*& rear, int pos)
{
    node* temp = new node;
    temp->priority = head->priority;
    temp->isPrint = head->isPrint;
}

void priorityPrinting(node*& head, int pos)
{
}
