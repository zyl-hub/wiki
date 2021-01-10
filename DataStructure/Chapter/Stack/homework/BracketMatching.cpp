#include <iostream>
using namespace std;

struct node {
    char data = 't';
    node* next = NULL;
};

void push(node*& head, char bracket);

void pop(node*& head);

void isMatched(node* head);

int main()
{
    int n;
    char bracket;
    node* head = new node;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int operation;
        cin >> operation;
        if (operation == 1) {
            cin >> bracket;
            push(head, bracket);
        }
        if (operation == 2) {
            pop(head);
        }
        if (operation == 3) {
            cout << head->data << endl;
        }
        if (operation == 4) {
            isMatched(head);
        }
    }

    return 0;
}

void push(node*& head, char bracket)
{
    node* newHead = new node;
    newHead->data = bracket;
    newHead->next = head;
    head = newHead;
}

void pop(node*& head)
{
    head = head->next;
}

void isMatched(node* head)
{
    node* tempStack = new node;
    node* temp = head;
    while (temp->next != NULL) {
        bool parenthesesPair = (tempStack->data == ')' && temp->data == '(');
        bool bracketPair = (tempStack->data == ']' && temp->data == '[');
        bool bigParenthesesPair = (tempStack->data == '}' && temp->data == '{');
        bool allPair = parenthesesPair || bracketPair || bigParenthesesPair;
        if (allPair) {
            pop(tempStack);
        } else {
            push(tempStack, temp->data);
        }
        temp = temp->next;
    }
    if (tempStack->data == 't') {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
