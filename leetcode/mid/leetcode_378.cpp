class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> nums;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                nums.push_back(matrix[i][j]);
            }
        }
        make_heap(nums.begin(), nums.end(), greater<int>());
        for (int i = 0; i < k-1; i++) {
            pop_heap(nums.begin(), nums.end(),greater<int>());
            nums.pop_back();
            //make_heap(nums.begin(), nums.end(), greater<int>());
        }
        return nums[0];

    }
};
