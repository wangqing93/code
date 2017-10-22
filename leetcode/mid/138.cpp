#include <iostream>

using namespace std;


struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return NULL;
        RandomListNode* copy_head = new RandomListNode(head->label);
        RandomListNode* temp = head;
        RandomListNode* copy_temp = copy_head;
        RandomListNode* temp1;
        //new node copy next
        while(temp!=NULL) {
            if (temp->next == NULL) {
                temp->next = copy_temp;
                break;
            }
            temp1 = temp->next;
            temp->next = copy_temp;
            copy_temp->next = temp1;
            temp = temp1;
            RandomListNode* copy_temp1 = new RandomListNode(temp->label);
            copy_temp = copy_temp1;
        }
        //copy random
        temp = head;
        copy_temp = copy_head;
        while(temp != NULL) {
            if (temp->random != NULL)
                copy_temp->random = temp->random->next;
            else {
                copy_temp->random = NULL;
            }
            if (temp->next->next == NULL)
                break;
            temp = temp->next->next;
            copy_temp = temp->next;
        }
        //restore next
        temp = head;
        copy_temp = copy_head;
        while(temp != NULL) {
            temp->next = copy_temp->next;
            if (temp->next == NULL)
                break;
            copy_temp->next = temp->next->next;
            temp = temp->next;
            copy_temp = copy_temp->next;
        }
        return copy_head;
    }
};
int main()
{
    RandomListNode* n1 = new RandomListNode(-1);
    RandomListNode* n2 = new RandomListNode(-1);
    RandomListNode* n3 = new RandomListNode(3);
    n1->next = n2;
    //n2->next = n3;
    Solution t;
    RandomListNode* nn1 = t.copyRandomList(n1);
    while (nn1 != NULL) {
        cout << nn1->label << endl;
        nn1 = nn1->next;
    }
    cout << "Hello world!" << endl;
    return 0;
}
