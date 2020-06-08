class Solution {
public:
    int search(vector<int>& nums, int target) {
        int startIndex = left_bound(nums, target);
        int endIndex = right_bound(nums,target);
        if ( startIndex!= -1 && endIndex != -1) {
            return endIndex-startIndex+1;
        }
        return 0;
    }

    int left_bound(vector<int> num, int target) {
        int l = 0, r = num.size()-1;
        while( l <= r) {
            int mid = l + (r-l)/2;
            if (num[mid] >= target)
                r = mid-1;
            else
                l = mid+1;
        }
        if (l < num.size() && num[l] == target)
            return l;
        return -1;
        
    }

    int right_bound(vector<int> num, int target) {
        int l = 0, r = num.size()-1;
        while( l <= r) {
            int mid = l + (r-l)/2;
            if (num[mid] <= target)
                l = mid+1;
            else
                r = mid-1;
        }
        if (l <= num.size() && l >0 && num[l-1] == target)
            return l-1;
        return -1;
    }
};
