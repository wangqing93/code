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
    int max_sum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        maxSinglePathSum(root);
        return max_sum;
    }

    int maxSinglePathSum(TreeNode* root) {
        int val = root ->val;
        int left_val = maxSinglePathSum(root->left);
        int right_val = maxSinglePathSum(root->right);
        if (left_val > 0)
            val += left_val;
        if (right_val > 0)
            val += right_val;
        if (val > max_sum)
            max_sum = val;
        return max(root->val, root->val + max(left_val, right_val));
    }
};

int main()
{
    Solution t;
    return 0;
}
