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
    TreeNode* recoverFromPreorder(string S) {
        vector<int> nums;
        vector<int> depths;
        stack<pair<int, TreeNode*>> indexs;
        string tempNum="";
        int tempDepth = 0;
        for (int i = 0 ; i < S.length(); i++) {
            if (S[i] == '-') {
                if (tempNum!="" ) {
                    depths.push_back(tempDepth);
                    nums.push_back(atoi(tempNum.c_str()));
                    //cout  << nums[nums.size()-1] << " " << depths[nums.size()-1]  << endl;
                    tempNum="";
                    tempDepth=0;
                }
                tempDepth++;
            } else {
                tempNum+=S[i];
            }
        }
        depths.push_back(tempDepth);
        nums.push_back(atoi(tempNum.c_str()));
        indexs.push(make_pair(0, new TreeNode(nums[0])));
        //cout  << nums[nums.size()-1] << " " << depths[nums.size()-1]  << endl;
        int curIndex = 1;
        while (curIndex < depths.size()) {
            if (depths[curIndex] >= depths[indexs.top().first]) {
                indexs.push(make_pair(curIndex, new TreeNode(nums[curIndex])));
                curIndex++;
            } else {
                if (indexs.size() >= 2) {
                    pair<int, TreeNode*> temp1 = indexs.top();
                    indexs.pop();
                    pair<int, TreeNode*> temp2 = indexs.top();
                    if (depths[temp1.first] == depths[temp2.first]) {
                        indexs.pop();
                        indexs.top().second->left = temp2.second;
                        indexs.top().second->right = temp1.second;
                    }
                    if (depths[temp1.first] == depths[temp2.first]+1) {
                        temp2.second->left = temp1.second;
                    }
                }
            }
        }

        while (indexs.size() >= 2) {
            pair<int, TreeNode*> temp1 = indexs.top();
            indexs.pop();
            pair<int, TreeNode*> temp2 = indexs.top();
            if (depths[temp1.first] == depths[temp2.first]) {
                indexs.pop();
                indexs.top().second->left = temp2.second;
                indexs.top().second->right = temp1.second;
            }
            if (depths[temp1.first] == depths[temp2.first]+1) {
                temp2.second->left = temp1.second;
            }
        }

        return indexs.top().second;
        
    }
};
