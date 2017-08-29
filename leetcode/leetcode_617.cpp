#include <iostream>
using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //¸ÄÔÚt1ÉÏ
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        int temp1, temp2;
        TreeNode *temp3;
        if (t1 != NULL && t2 != NULL)
        {
            temp1 = (t1==NULL)?0:t1->val;
            temp2 = (t2==NULL)?0:t2->val;
            temp3 = new TreeNode(temp1+temp2);
            temp3->left = mergeTrees(t1->left, t2->left);
            temp3->right = mergeTrees(t1->right, t2->right);
            return temp3;
        } else
            return t1==NULL?t2:t1;

    }
};
