#include <iostream>

using namespace std;
#define INT_MIN 0x80000000

// time exceed
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left_res, right_res;
        if (root->left != NULL)
            left_res = maxPathSum(root->left);
        else
            left_res = INT_MIN;
        if (root->right != NULL)
            right_res = maxPathSum(root->right);
        else
            right_res = INT_MIN;
        return max(max(left_res, right_res), max(findMaxPath(root->left),0)+max(findMaxPath(root->right),0)+root->val);
    }

    int findMaxPath(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left_max_res = findMaxPath(root->left);
        int right_max_res = findMaxPath(root->right);
        return root->val+max(max(left_max_res, right_max_res), 0);
    }
};

int main()
{
    Solution t;
    return 0;
}
