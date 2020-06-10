class Solution {
public:
    /*vector<int> sortArray(vector<int>& nums) {
        //排序算法：快排，归并，冒泡
    }*/

    /*vector<int> sortArray(vector<int>& nums) {
        //排序算法：快排，归并，冒泡
        //冒泡：最小的元素在前面
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (nums[i] > nums[j])
                    swap(nums[i], nums[j]);
            }
        }
        return nums;
    }*/

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }

    void quickSort(vector<int>& nums, int left, int right) {
        /*for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;*/

        if (left >= right)
            return;
        int key = nums[left];
        int i = left, j = right; // [left, right]
        while (i < j) {
            while(i < j && nums[j] >= key) j--;
            if (i < j) {
                nums[i] = nums[j];
                i++;
            }
            while(i < j && nums[i] <= key) i++;
            if (i < j) {
                nums[j] = nums[i];
                j--;
            }
        }
        //cout << left << " " << right << " " << key << " " << i << endl;
        nums[i] =  key;  // key放在了i的位置
        quickSort(nums, left, i-1);
        quickSort(nums, i+1, right);
    }
};
