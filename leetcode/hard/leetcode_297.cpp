/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //数据结构的相互转换，我刚开始还想到vector和树的相互转换，比如先序遍历和中序遍历
        //其实不用，按照举例，我们可以用BFS即可，每个元素用，分割
        //string转换成int，可以是atoi(str.c_str())
        //int 转换成string，可以是to_string()
        if (root == NULL)
            return "";
        string res = "";
        queue<TreeNode*> nodes;
        nodes.push(root);
        res += to_string(root->val);
        res += ",";
        int levelNums;
        while(!nodes.empty()) {
             levelNums = nodes.size();
            for (int i = 0; i < levelNums; i++) {
                TreeNode* t = nodes.front();
                nodes.pop();
                if (t!= NULL && t->left != NULL) {
                    res += to_string(t->left->val);
                    nodes.push(t->left);
                } else {
                    res += "null";
                }
                res += ",";
                if (t!= NULL && t->right != NULL) {
                    res += to_string(t->right->val);
                    nodes.push(t->right);
                } else {
                    res += "null";
                }
                res += ",";
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "")
            return NULL;
        vector<string> nodeValStr = splitStr(data);
        //第一层元素有1个，不为空则下一层2h个
        //该层元素x个，为null就没有孩子了，不为null有2个孩子
        int len = 1;
        int index = 0;
        queue<TreeNode*> nodes;
        TreeNode* root = new TreeNode(atoi(nodeValStr[0].c_str()));
        nodes.push(root);
        while (!nodes.empty()) {
            len = nodes.size();
            //cout << len << " " << index << " " << endl;
            //level [index, index+len), next[index+len, index+len+templen)
            int incre = 0;
            for (int i = 0; i < len; i++) {
                TreeNode* node = nodes.front();
                nodes.pop();
                if (node == NULL)
                    continue;
                string left = nodeValStr[index+len+incre];
                incre++;
                if (left == "null") {
                    node->left = NULL;
                    nodes.push(NULL);
                }
                else {
                    TreeNode* leftNode = new TreeNode(atoi(left.c_str()));
                    nodes.push(leftNode);
                    node->left = leftNode;
                }
                string right = nodeValStr[index+len+incre];
                incre++;
                if (right == "null") {
                    node->right = NULL;
                    nodes.push(NULL);
                }
                else {
                    TreeNode* rightNode = new TreeNode(atoi(right.c_str()));
                    nodes.push(rightNode);
                    node->right = rightNode;
                }
            }
            index+=len;
        }
        return root;
    }
    
    vector<string> splitStr(string s) {
        vector<string> res;
        string oneres = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ',') {
                res.push_back(oneres);
                oneres = "";
            } else {
                oneres+=s[i];
            }
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
