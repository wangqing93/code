#include <iostream>

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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* cur = head;
        ListNode* curn = head->next;
        ListNode* curnn;
        cur->next = NULL;
        while(cur != NULL && curn != NULL)
        {
            curnn = curn->next;
            curn->next = cur;
            cur = curn;
            curn = curnn;
        }
        return cur;
    }
};

int main()
{
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    n1->next = n2;
    n2->next = n3;
    Solution test;
    ListNode* re = test.reverseList(n1);
    while(re != NULL)
    {
        cout << re->val << endl;
        re = re->next;
    }
    cout << "Hello world!" << endl;
    return 0;
}
