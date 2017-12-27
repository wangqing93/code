

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0; int j = nums.size()-1;
        if (nums.size() == 0) return 0;
        if ( i == j) {
            if (nums[i] == val)
            {
                nums.clear();
                return 0;
            } else 
            {
                return 1;
            }
        }
        while (i < nums.size() && j >= 0 && i < j) {
            while (j >= 0 && nums[j] == val) j--;
            while (i < nums.size() && nums[i] != val) i++;
            if (i < nums.size() && j >= 0 && i < j)
            {
                swap(nums[i], nums[j]);
                i++;
                j--;
            } 
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val)
            {
                nums.resize(i);
                return i;
            }
        }
        return nums.size();
    }
};
