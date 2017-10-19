#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    //quicksort
    ListNode* sortList1(ListNode* head) {
        vector<int> datas;
        ListNode* t = head;
        while (t != NULL) {
            datas.push_back(t->val);
            t = t -> next;
        }
        sort(datas.begin(), datas.end());
        t = head;
        int i = 0;
        while( t != NULL)
        {
            t->val = datas[i];
            i++;
            t = t -> next;
        }
        return head;
    }
    //insert sort
    ListNode* sortList2(ListNode* head) {
        if (head == NULL or head->next == NULL)
            return head;
        ListNode* sortedList = head, *t = NULL, *pre = NULL;
        ListNode* unsortedList = head->next, *next_unsortedList = NULL;
        head->next = NULL;
        while(unsortedList!=NULL) {
            next_unsortedList = unsortedList->next;
            unsortedList->next = NULL;
            t = sortedList;
            pre = NULL;
            while(t!= NULL && t->val < unsortedList->val) {
                pre = t;
                t = t->next;
            }
            if (t == NULL) {
                pre->next = unsortedList;
            } else {
                if (pre == NULL) {
                    sortedList = unsortedList;
                    unsortedList->next = t;
                } else {
                    pre->next = unsortedList;
                    unsortedList->next = t;
                }
            }
            unsortedList = next_unsortedList;
        }
        return sortedList;
    }
    //merge sort
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* t = head;
        int n = 0, i = 1;
        while(t!=NULL){
            n++;
            t = t->next;
        }
        t = head;
        while(i < n/2) {
            i++;
            t = t->next;
        }
        ListNode* nt = t->next;
        t->next = NULL;
        ListNode* head1 = sortList(head);
        ListNode* res = head1;
        while(res != NULL)
        {
            cout << res->val <<" ->";
            res = res->next;
        }
        cout << endl;
        ListNode* head2 = sortList(nt);
        res = head2;
        while(res != NULL)
        {
            cout << res->val <<" ->";
            res = res->next;
        }
        cout << endl;
        return mergeList(head1, head2);

    }
    ListNode* mergeList(ListNode* head1, ListNode* head2) {
        if (head2 == NULL)
            return head1;
        if (head1 == NULL)
            return head2;
        ListNode *cur2 = head2, *next_cur2 = NULL;
        ListNode *cur1 = head1, *pre_cur1 = NULL;
        ListNode *sort_head = cur1;
        while(cur2!= NULL) {
            next_cur2 = cur2->next;
            while(cur1 != NULL && cur1->val < cur2->val) {
                pre_cur1 = cur1;
                cur1 = cur1->next;
            }
            if (cur1 == NULL) {
                pre_cur1->next = cur2;
                break;
            } else {
                if (pre_cur1 == NULL) {
                    cur2->next = cur1;
                    cur1 = cur2;
                    sort_head = cur1;
                } else {
                    pre_cur1->next = cur2;
                    cur2->next = cur1;
                    cur1 = cur2;
                }
            }
            cur2 = next_cur2;
        }
        return sort_head;
    }
};

int main()
{
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;
    Solution t;
    ListNode* res = t.sortList(n1);
    //ListNode* res = n1;
    while(res != NULL)
    {
        cout << res->val <<" ->";
        res = res->next;
    }
    cout << "Hello world!" << endl;
    return 0;
}
