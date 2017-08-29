
#include <stdlib.h>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
 };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int add_val = 0;
        vector<int> mark;
        while(l1 != NULL)
        {
            if (l2 == NULL)
                break;
            l1->val = l1->val + l2->val + add_val;
            if (l1->val > 9)
            {
                add_val = 1;
            } else
                add_val = 0;
            mark.push_back(l1->val%10);
            l2 = l2->next;
            l1 = l1->next;
        }
        int mark_size = mark.size();
        if (l1 == NULL)
        {
            while (l2 != NULL)
            {
                mark.push_back(l2->val);
                l2 = l2->next;
            }
        } else
        {
            while (l1 != NULL)
            {
                mark.push_back(l1->val);
                l1 = l1->next;
            }
        }
        if (mark.size() == 0)
            return NULL;
        ListNode* start = new ListNode(mark[0]);
        ListNode* pre = start;
        for (int i = 1; i < mark.size(); i++)
        {
            if (i >= mark_size && add_val == 1)
            {
                mark[i]++;
                if (mark[i] > 9)
                {
                    mark[i] = mark[i]%10;
                    add_val = 1;
                }else
                    add_val = 0;
            }
            ListNode* temp = new ListNode(mark[i]+1);
            pre->next = temp;
            pre = temp;
        }
        return start;
    }
    ListNode* addTwoNumbers_v2(ListNode* l1, ListNode* l2) {
        ListNode* pre = new ListNode(0);
        ListNode* start;
        start = pre;
        int v1,v2,add_v=0;
        while(l1 != NULL || l2 != NULL)
        {
            v1 = (l1 != NULL) ? l1->val : 0;
            v2 = (l2 != NULL) ? l2->val : 0;
            ListNode* newl = new ListNode(v1 + v2 + add_v);
            add_v = (newl->val > 9) ? 1 : 0;
            newl->val %= 10;
            l1 = (l1 != NULL) ? l1->next : NULL;
            l2 = (l2 != NULL) ? l2->next : NULL;
            pre->next = newl;
            pre = newl;
        }
        if (add_v == 1)
            pre->next = new ListNode(1);
        return start->next;
    }
};
