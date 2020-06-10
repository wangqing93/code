class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int **dp = new int*[n];
        for (int i = 0; i < n; i++) {
            dp[i] = new int[n];
            dp[i][i] = 1;
            for (int j = i-1; j >=0; j--)
                dp[i][j] = 0;
        }
        for (int i = n-1; i >= 0; i--) { // 由下及上，由左及右；斜着遍历有点困难
            for (int j = i+1; j < n; j++) {
                if (s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);  
                //cout << i << " " << j << " " << dp[i][j] << endl; 
            }
        }
        return dp[0][n-1];
    }
};
