#include <iostream>
#include <vector>
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

class Solution {
public:
    vector<int> reversePrint(ListNode* head)
    {
        vector<int> reverseLinkList;
        ListNode* newHead = NULL;
        ListNode* delTemp = NULL;
        while (head != NULL) {
            ListNode* p = new ListNode(head->val);
            p->next = newHead;
            newHead = p;
            head = head->next;
        }
        while (newHead != NULL) {
            reverseLinkList.push_back(newHead->val);
            newHead = newHead->next;
        }
        return reverseLinkList;
    }
};
