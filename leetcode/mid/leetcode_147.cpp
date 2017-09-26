#include <iostream>
#include <stdlib.h>

using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* res = head;
        ListNode* temp = NULL;
        ListNode* pretemp = NULL;
        ListNode* dealnode = head->next;
        res->next = NULL;
        while(dealnode != NULL)
        {
            temp = res;
            pretemp = NULL;
            while (temp != NULL && temp->val <= dealnode->val)
            {
                pretemp = temp;
                temp = temp->next;
            }
            if (temp == NULL)
            {
                pretemp->next = dealnode;
                dealnode = dealnode->next;
                pretemp->next->next = NULL;
                continue;
            }
            if(temp->val > dealnode->val)
            {
                if (pretemp != NULL)
                {
                    pretemp->next = dealnode;
                    dealnode = dealnode->next;
                    pretemp->next->next = temp;
                } else
                {
                    temp = dealnode->next;
                    pretemp = dealnode;
                    pretemp->next = res;
                    res = pretemp;
                    dealnode = temp;
                }
            }
        }
        return res;
    }
};

int main()
{
    ListNode* n1 = new ListNode(2);
    ListNode* n2 = new ListNode(1);
    n1->next = n2;
    Solution test;
    ListNode* res = test.insertionSortList(n1);
    while(res != NULL)
    {
        cout << res->val<< " ";
        res = res->next;
    }

    cout << "Hello world!" << endl;
    return 0;
}
