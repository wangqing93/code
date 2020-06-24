class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res;
        int absRes = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int key = target-nums[i];
            int l = i+1;
            int r = nums.size()-1;
            while(l < r) {
                if (abs(nums[l]+nums[r]-key) < absRes) {
                    absRes = abs(nums[l]+nums[r]-key);
                    res = nums[l]+nums[r]+nums[i];
                    //cout << nums[l] << " " << nums[r] << " " << nums[i] <<  endl;
                }
                if (nums[l] + nums[r] < key) {
                    l++;
                } else if (nums[l] + nums[r] == key) {
                    return target;
                } else {
                    r--;
                }
            }
        }
        return res;
    }
};
