class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //综合等于sum，选择一些数的和使得它等于sum/2
        //dp[i][j] 关键是状态转移方程
        //dp[i][j] = 1 if dp[i-1][j]=1
        //dp[i][j] = 1 if dp[i-1][j-nums[i]] = 1
        //最多200*100

        bool **dp = new bool*[200];
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum%2 == 1)
            return false;

        for (int i = 0; i < 200; i++) 
            dp[i] = new bool[sum+1];
        dp[0][0] = true;
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < sum+1; j++) {
                if (i >0 && dp[i-1][j]) {
                    dp[i][j] = true;
                    continue;
                }
                if (i >0 && j-nums[i] >= 0) {
                    if (dp[i-1][j-nums[i]]) {
                        dp[i][j] = true;
                        continue;
                    }    
                }
                if (i == 0 && j == nums[i])
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (dp[i][sum/2])
                return true;
        }

        return false;
    }
};
