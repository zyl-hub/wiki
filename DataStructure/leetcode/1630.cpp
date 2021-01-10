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

ListNode* reverseList(ListNode* head);

int main()
{

    return 0;
}

ListNode* reverseList(ListNode* head)
{
    ListNode* newHead = NULL;
    ListNode* delTemp = NULL;
    while (head != NULL) {
        ListNode* p = new ListNode(head->val);
        p->next = newHead;
        newHead = p;
        delTemp = head;
        head = head->next;
        delete delTemp;
    }
    return newHead;
}
