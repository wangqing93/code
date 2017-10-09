#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> res = TraverseTree(root);
        for (int i = 1; i < res.size(); i++)
        {
            if (res[i] < res[i-1])
                return false;
        }
        return true;
    }
    vector<int> TraverseTree(TreeNode* root) {
        if (root == NULL)
            return vector<int>();
        vector<int> left_res = TraverseTree(root->left);
        left_res.push_back(root->val);
        vector<int> right_res = TraverseTree(root->right);
        left_res.insert(left_res.end(), right_res.begin(), right_res.end());
        return left_res;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
