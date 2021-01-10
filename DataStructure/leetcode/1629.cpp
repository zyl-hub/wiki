#include <cstddef>
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

ListNode* getKthFromEnd(ListNode* head, int k);

int main()
{
    ListNode *head, *rear;
    head = new ListNode(1);
    rear = head;
    for (int i = 2; i < 7; i++) {
        ListNode* p = new ListNode(i);
        rear->next = p;
        rear = p;
    }
    ListNode* tempHead;
    tempHead = head;
    //while (tempHead->next != NULL) {
    //cout << tempHead->val;
    //tempHead = tempHead->next;
    //}
    head = getKthFromEnd(head, 2);
    return 0;
}

//answer
ListNode* getKthFromEnd(ListNode* head, int k)
{
    int len = -1;
    ListNode* tempHead = head;
    while (tempHead != NULL) {
        tempHead = tempHead->next;
        len++;
    }
    cout << len;
    for (int i = 0; i < len - k; i++) {
        head = head->next;
    }
    return head;
}
