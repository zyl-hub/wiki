#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(NULL)
    {
    }
};

ListNode* deleteNode(ListNode* head, int val);

int main()
{
    ListNode* head = NULL;
    ListNode* rear = NULL;
    head = new ListNode(1);
    rear = head;
    for (int i = 2; i < 7; i++) {
        ListNode* p = new ListNode(i);
        rear->next = p;
        rear = p;
    }
    deleteNode(head, 4);
    while (head->next != NULL) {
        cout << head->val;
        head = head->next;
    }

    return 0;
}

ListNode* deleteNode(ListNode* head, int val)
{
    ListNode* prev;
    ListNode* temp;
    temp = head;
    if (head->val == val) {
        head = head->next;
        return head;
    }
    bool flag = 1;
    while (flag == 1) {
        if (temp->val == val) {
            flag = 0;
            prev->next = temp->next;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
