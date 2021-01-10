#include <iostream>
#include <string.h>
using namespace std;

union Data {
    int intData;
    double doubleData;
    char charData;
};

struct node {
    Data data;
    node* next;
};

int main()
{
    char type[7];
    int m = 0, n = 0;
    cin >> type;
    cin >> m >> n;
    node* head;
    node* rear;
    head = new node;
    rear = head;
    if (strcmp(type, "int") == 0) {
        int tempData = 0;
        for (int i = 0; i < n; i++) {
            cin >> tempData;
            rear->data.intData = tempData;
            node* p = new node;
            rear->next = p;
            rear = p;
        }
        for (int i = 0; i < m; i++) {
            cin >> tempData;
            rear->data.intData = tempData;
            node* p = new node;
            rear->next = p;
            rear = p;
        }
        while (head->next != NULL) {
            cout << head->data.intData << ' ';
            head = head->next;
        }
    }
    if (strcmp(type, "double") == 0) {
        double tempData = 0;
        for (int i = 0; i < n; i++) {
            cin >> tempData;
            rear->data.doubleData = tempData;
            node* p = new node;
            rear->next = p;
            rear = p;
        }
        for (int i = 0; i < m; i++) {
            cin >> tempData;
            rear->data.doubleData = tempData;
            node* p = new node;
            rear->next = p;
            rear = p;
        }
        while (head->next != NULL) {
            cout << head->data.doubleData << ' ';
            head = head->next;
        }
    }
    if (strcmp(type, "char") == 0) {
        char tempData = 0;
        for (int i = 0; i < n; i++) {
            cin >> tempData;
            rear->data.charData = tempData;
            node* p = new node;
            rear->next = p;
            rear = p;
        }
        for (int i = 0; i < m; i++) {
            cin >> tempData;
            rear->data.charData = tempData;
            node* p = new node;
            rear->next = p;
            rear = p;
        }
        while (head->next != NULL) {
            cout << head->data.charData << ' ';
            head = head->next;
        }
    }
    return 0;
}
