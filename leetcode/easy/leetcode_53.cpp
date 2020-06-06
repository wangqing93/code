class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int start_sum=0;
        int cur_sum =nums[0];
        int max_sum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if (cur_sum + nums[i] > nums[i]) {
                cur_sum += nums[i];
                if (max_sum < cur_sum)
                    max_sum = cur_sum;
            } else {
                start_sum = i;
                cur_sum = nums[i];
                if (max_sum < cur_sum)
                    max_sum = cur_sum;
            }
        }
        return max_sum;
    }
};
