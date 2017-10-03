#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> path;
        dfs(nums, 0, path, res);
        return res;
    }

   void dfs(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res) { //[]
        if (path.size() != 0)
            res.push_back(path);
        for (int i = start; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            dfs(nums, i+1, path, res);
            path.pop_back();
        }
    }
    void testPrint(vector<int> nums)
    {
        vector<vector<int>> res = subsets(nums);
        for (int i = 0; i < res.size(); i++)
        {
            for (int j = 0; j < res[i].size(); j++)
                cout << res[i][j] << " ";
            cout << endl;
        }
    }
};

int main()
{
    vector<int>  testcase;
    testcase.push_back(1);
    testcase.push_back(2);
    testcase.push_back(3);
    Solution t;
    t.testPrint(testcase);
    cout << "Hello world!" << endl;
    return 0;
}
