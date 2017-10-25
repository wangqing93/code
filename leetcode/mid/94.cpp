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
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) { //left mid right
        if (root == NULL)
            return res;
        inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);
        return res;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
