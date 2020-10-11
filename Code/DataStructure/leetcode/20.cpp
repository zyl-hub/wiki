#include <iostream>
#include <string>
using namespace std;

struct node {
    char data = 't';
    node* next = NULL;
};

int main()
{
    string s = "(()";
    node* head = new node;
    for (int i = 0; i < s.length(); i++) {
        bool parenthesesPair = (head->data == '(' && s[i] == ')');
        bool bracketPair = (head->data == '[' && s[i] == ']');
        bool bigParenthesesPair = (head->data == '{' && s[i] == '}');
        bool allPair = parenthesesPair || bracketPair || bigParenthesesPair;
        if (allPair) {
            head = head->next;
        } else {
            node* tempHead = new node;
            tempHead->data = s[i];
            tempHead->next = head;
            head = tempHead;
        }
    }
    if (head->data == 't') {
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}
