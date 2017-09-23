#include <iostream>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL)
            return false;
        if (head->next == NULL)
            return false;
        if (head->next->next == NULL)
            return false;
        ListNode *headTwoStep = head->next->next;
        if (head == headTwoStep)
            return true;
        while (head->next != NULL && headTwoStep->next != NULL && headTwoStep->next->next != NULL && headTwoStep != head)
        {
            head = head->next;
            headTwoStep = headTwoStep->next->next;
        }
        if (headTwoStep == head)
            return true;
        else
            return false;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
