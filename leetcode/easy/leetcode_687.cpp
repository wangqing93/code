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
    int max_len = 0;
    int longestUnivaluePath(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left_res = longestUnivaluePath(root->left);
        int right_res = longestUnivaluePath(root->right);
        return max(max(left_res, right_res), findMaxPath(root->left, root->val)+findMaxPath(root->right, root->val));
    }

    int findMaxPath(TreeNode* root, int val) {
        if (root == NULL || root->val != val)
            return 0;
        int left_max_res = findMaxPath(root->left, val);
        int right_max_res = findMaxPath(root->right, val);
        return 1+max(left_max_res, right_max_res);
    }
};

int main()
{
    Solution t;
    return 0;
}
