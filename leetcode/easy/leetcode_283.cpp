#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int num0 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                num0++;
            else
                nums[i-num0] = nums[i];
        }
        for (int i = 0; i < num0; i++)
        {
            nums[nums.size()-1-i] = 0;
        }
    }
};
