class Solution {
public:
 vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
    vector<int> path;
        dfs(nums, path);
        return res;
    }

    void dfs(vector<int> nums, vector<int> path) {
        if (nums.size() == 0) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            path.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            dfs(nums, path);
            nums.insert(nums.begin()+i, path[path.size()-1]);
            path.pop_back();
        }
    }
};
