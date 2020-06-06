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
    //递归构造法，分而治之，做过的题目，三刷
    vector<int> preData;
    vector<int> inData;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preData.assign(preorder.begin(), preorder.end());
        inData.assign(inorder.begin(), inorder.end());
        return findTree(0, preorder.size()-1, 0, preorder.size()-1);
    }


    TreeNode* findTree(int startPre, int endPre, int startIn, int endIn) { //[]
        if (startIn > endIn)
            return NULL;
        int rootV = preData[startPre];
        int rootPos = -1;
        for (int i = startIn; i <= endIn; i++) {
            if (inData[i] == rootV) {
                rootPos = i;
                break;
            }
        } 
        TreeNode* root = new TreeNode(rootV);
        root->left = findTree(startPre+1, startPre+rootPos-startIn, startIn, rootPos-1);
        root->right = findTree(startPre+rootPos-startIn+1, endPre, rootPos+1, endIn);
        return root;
    }
};
