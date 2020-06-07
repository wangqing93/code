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
    int minDepth(TreeNode* root) {
        int step = 0;
        if (root == NULL)
            return step;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty()) {
            int n = nodes.size();
            step++;
            for (int i = 0; i < n; i++) {
                TreeNode* temp = nodes.front();
                nodes.pop();
                if (temp->left == NULL && temp->right == NULL) {
                    return step;
                } else {
                    if (temp->left != NULL)
                        nodes.push(temp->left);
                    if (temp->right != NULL)
                        nodes.push(temp->right);
                }
            }
        }
        return step;
    }
};
