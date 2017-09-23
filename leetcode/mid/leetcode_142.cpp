#include <iostream>
#include <stdlib.h>

using namespace std;



//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return NULL;
        ListNode *OneStep = head->next;
        ListNode *TwoStep = head->next->next;
        while (OneStep->next != NULL && TwoStep->next != NULL && TwoStep->next->next != NULL && OneStep != TwoStep)
        {
            OneStep = OneStep->next;
            TwoStep = TwoStep->next->next;
        }
        if (OneStep == TwoStep)
        {
            while(head->next != NULL && OneStep->next != NULL && head != OneStep)
            {
                head = head->next;
                OneStep = OneStep->next;
            }
            return head;
        }
        return NULL;
    }
};
int main()
{
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(0);
    ListNode* n4 = new ListNode(-4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;
    Solution test;
    ListNode* res = test.detectCycle(n1);
    cout << res->val;
    system("pause");
    return 0;
}
