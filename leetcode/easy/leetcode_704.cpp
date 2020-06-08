class Solution {
public:
    int search(vector<int>& nums, int target) {
        //元素不重复，如果元素有重复的，没办法找到最左边的那个数
        int l = 0;
        int r = nums.size()-1;
        while(l <= r) {
            int mid = l + (r-l)/2;  //可以避免l+r越界
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                r = mid-1;
            else
                l = mid+1; 
        }
        return -1;
    }
};
