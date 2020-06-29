class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end(), less<int>());
        for (int i = 0; i < k -1; i++) {
            pop_heap(nums.begin(), nums.end(), less<int>());
            nums.pop_back();
        }
        return nums[0];
    }
};
