#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int ori_r = nums.size(), ori_c = nums[0].size();
        if (r * c != ori_r * ori_c)
            return nums;
        vector<vector<int>> res;
        for (int i = 0; i < r; i++)
        {
            vector<int> temp;
            for (int j = 0; j < c; j++)
            {
                temp.push_back(0);
            }
            res.push_back(temp);
        }
        for (int i = 0; i < ori_r; i++)
        {
            for (int j = 0; j < ori_c; j++)
            {
                res[(i*ori_c+j)/c][(i*ori_c+j)%c] = nums[i][j];
            }
        }
        return res;
    }
};
