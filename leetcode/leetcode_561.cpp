#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()/2; i++)
            res += nums[i*2];
        return res;
    }
};
