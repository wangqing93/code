class Solution {
public:
    vector<vector<int>> res;
    int end;
    int num;
    vector<vector<int>> combine(int n, int k) {
        end = n;
        num = k;
        vector<int> path;
        dfs(1, path);
        return res;
    }

   // dfs绘图是关键
    void dfs(int start, vector<int> path) {
        if (path.size() == num) {
            res.push_back(path);
            return;
        }
        for (int i = start; i <= end ;i++) {
            path.push_back(i);
            dfs(i+1, path);
            path.pop_back();
        }
    }
};
