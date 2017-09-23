#include <iostream>
#include <algorithm>

using namespace std;



//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {

public:
    TreeNode* n1 = NULL;
    TreeNode* n2 = NULL;
    TreeNode* pre = NULL;
    void travese(TreeNode* root)
    {
        if (root == NULL)
            return;
        travese(root->left);
        //root
        if (root != NULL && pre != NULL && pre->val > root->val)
        {
            if (n1 == NULL)
                n1 = pre;
            if (n1 != NULL)
                n2 = root;
        }
        pre = root;
        travese(root->right);
    }

    void recoverTree(TreeNode* root) {
        travese(root);
        if (n1 != NULL && n2 != NULL)
        {
            //cout << n1->val << " " << n2->val;
            swap(n1->val, n2->val);
        }



    }
};
int main()
{
    TreeNode* n1 = new TreeNode(0);
    TreeNode* n2 = new TreeNode(1);
    n1->left = n2;

    Solution test;
    test.n1 = NULL;
    test.n2 = NULL;
    test.recoverTree(n1);
    cout << "Hello world!" << endl;
    return 0;
}
