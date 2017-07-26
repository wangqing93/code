#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> mark, res;
        for (int i = 0; i < nums.size()+1; i++)
        {
            mark.push_back(0);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            mark[nums[i]]=1;
        }
        for (int i = 1; i < nums.size()+1; i++)
        {
            if (mark[i] == 0)
                res.push_back(i);
        }
        return res;
    }
};
