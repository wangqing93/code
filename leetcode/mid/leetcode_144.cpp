#include <iostream>
#include <vector>

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
    vector<int> preorderTraversal(TreeNode* root) {
        // mid left right
        vector<int> res, leftres, rightres;
        if (root != NULL)
        {
            res.push_back(root->val);
        }
        else
            return res;
        leftres = preorderTraversal(root->left);
        rightres = preorderTraversal(root->right);
        for (int i = 0; i < leftres.size(); i++)
            res.push_back(leftres[i]);
        for (int i = 0; i < rightres.size(); i++)
            res.push_back(rightres[i]);
        leftres.clear();
        rightres.clear();
        return res;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
