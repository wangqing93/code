class Solution {
public:
    //暴力的动态规划，W很大的时候，复杂度也是接近于n方
    /*double new21Game(int N, int K, int W) {
        //看了题解恍然大悟
        double * dp= new double[K+W];
        for (int i = K; i <= N && i < (K+W); i++)
            dp[i] = 1;
        for (int i = N+1; i < K+W; i++)
            dp[i] = 0;
        for (int i = K-1; i >= 0; i--) {
            double temp = 0;
            for (int j = 1; j <= W; j++) {
                temp += dp[i+j];
            }
            
            dp[i] = temp*1.0/W;
            //cout << i << " " << dp[i] << " " << temp << endl;
        }
        return dp[0];
    }*/

    //优化的动态规划
    double new21Game(int N, int K, int W) {
        double * dp= new double[K+W];
        for (int i = K; i <= N && i < (K+W); i++)
            dp[i] = 1;
        for (int i = N+1; i < K+W; i++)
            dp[i] = 0;
        double sum = (N-K+1);
        for (int i = K-1; i >= 0; i--) {
            dp[i] = sum/W;
            sum = sum+dp[i]-dp[i+W];
            //cout << i << " " << dp[i] << " " << temp << endl;
        }
        return dp[0];
    }

};
