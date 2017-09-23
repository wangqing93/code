#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> temp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (temp.find(nums[i]) == temp.end())
                temp.insert(make_pair(nums[i],1));
            else
                return true;
        }
        return false;
    }
};
