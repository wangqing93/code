class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long int res= nums.size()*(nums.size()+1)/2;
        for (int i = 0; i < nums.size(); i++)
            res -=nums[i];
        return res;
    }
};