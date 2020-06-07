class Solution {
public:
    /*int change(int amount, vector<int>& coins) {
        //背包问题，选择coins的前i个，构成了amount；再新加入新的coins
        int n = coins.size();
        int** dp = new int*[n+1];
        for (int i = 0; i <= n; i++) {
            dp[i] = new int[amount+1];
            dp[i][0] = 1;  //不选是一种方案，构成amount=0
        }
        for (int i = 1; i <= amount; i++) {
            dp[0][i] = 0; //没有硬币，没法选，所以都是0
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (j - coins[i-1] >= 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
                //cout << i << " " << j << " " << dp[i][j] << endl;
            }
        }
        return dp[n][amount];
    }*/
    int change(int amount, vector<int>& coins) {
        //调试了一个小时，因为状态方程理解错了：dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]]
        //可以做状态压缩，因为只和前一个状态有关系
        int* dp = new int[amount+1];
        dp[0] = 1;
        for (int j = 1; j <= amount; j++) {
            dp[j] = 0;
        }
        for (int i = 0; i < coins.size(); i++) {
            //cout << i << " ****** " << endl;
            for (int j = 1; j <= amount; j++) {
                if (j-coins[i] >= 0)
                    dp[j] = dp[j] + dp[j-coins[i]];
                //cout << j << ": " << dp[j] << endl;
            }
        }
        return dp[amount];
    }
};
