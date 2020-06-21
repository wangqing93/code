/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //单边最大，在统计单边最大的过程中，找经过该节点的max值
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        sideMax(root);
        return res;
    }

    int sideMax(TreeNode* root) {
        if (root == NULL)
            return 0;
        int leftV = max(0, sideMax(root->left)); //单边最大，负值就不取了
        int rightV = max(0, sideMax(root->right));
        res = max(res, root->val + leftV + rightV);
        return root->val + max(leftV, rightV);
    }

    //debug mark  [2,-1]
};
