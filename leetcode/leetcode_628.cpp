#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        //可能有负数、0、正数，有3个数，每个数3种可能，有27种可能，但实际上不可能有0，因为这是最小的，那么每个数2种可能，8种
        if (nums[nums.size()-1] <= 0)
        {
            return nums[nums.size()-1] *nums[nums.size()-2] *nums[nums.size()-3];
        } else
        {

            return max(nums[nums.size()-1] *nums[nums.size()-2] *nums[nums.size()-3], nums[0]*nums[1]*nums[nums.size()-1]);
        }

    }
};
