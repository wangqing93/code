class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
         // 大于value 变为value，value= [0, MAX];
         sort(arr.begin(), arr.end());
         //i是可能的答案，values的集合
         vector<int> sumArr;
         int temp = 0;
         sumArr.push_back(temp);
         for (int i = 0; i < arr.size(); i++) {
             temp += arr[i];
             sumArr.push_back(temp);
         }
         sumArr.push_back(temp);
         int absMin = target;
         int resValue = 0;
         for (int i = 0; i <= arr[arr.size()-1]; i++) {
             
             auto xIndex = lower_bound(arr.begin(), arr.end(), i);
             int sumValue = sumArr[xIndex - arr.begin()] + (arr.end() - xIndex) * i;
             if (abs(sumValue-target) < absMin) {
                 absMin = abs(sumValue-target);
                 resValue = i;
             }
         }
         return resValue;
    }

    // 3 6 10 zhao 9 return 6
    // 3 6 10 zhao 2 return index=-1
    int findRightBound(vector<int> nums, int key) {
        int l = 0; 
        int r = nums.size(); //[l, r)
        while( l<r ) {
            int mid = l+(r-l)/2;
            if (nums[mid] > key)
                r = mid;
            else
                l = mid+1;
        }
        return l--;
    }
};
