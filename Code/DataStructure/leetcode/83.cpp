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

ListNode* deleteDuplicates(ListNode* head);

int main()
{
    ListNode *head, *rear;
    head = new ListNode(1);
    rear = head;
    for (int i = 2; i < 7; i++) {
        ListNode* p = new ListNode(2);
        rear->next = p;
        rear = p;
    }
    deleteDuplicates(head);
    //while (head != NULL) {
    //cout << head->val;
    //head = head->next;
    //}
    return 0;
}

ListNode* deleteDuplicates(ListNode* head)
{
    int prevData = 0;
    ListNode* temp;
    while (head->next != NULL) {
        prevData = head->val;
        temp = head->next;
        if (prevData == temp->val) {
            head->next = temp->next;
        }
        head = head->next;
    }
    return head;
}
