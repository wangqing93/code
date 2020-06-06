class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        int **dp = new int*[len+2];
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        for (int i = 0; i < len+2; i++) {
            dp[i] = new int[len+2];
            for (int j = i; j < len+2; j++) {
                if (i == j || abs(j-i)==1)
                    dp[i][j] = 0;
                else if (j-i == 2)
                    dp[i][j] = nums[i+1];
                else
                    dp[i][j] = 0;
            }
        }
        //cout << "test"  << endl;
        for (int i = len+1; i >= 0; i--) {
            for (int j = i; j < len+2; j++) {
                for (int k = i+1; k < j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + nums[i]*nums[k]*nums[j]+dp[k][j]);
                }
            }
        }
        return dp[0][len+1];
    }
};
