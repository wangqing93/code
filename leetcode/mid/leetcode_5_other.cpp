class Solution {
public:
    string longestPalindrome(string s) {
        //有奇数长度也有偶数长度，为了统一奇数长度，s之间的字符串添加#
        // s[i] == s[j], dp[i][j] = true; if (dp[i+1][j-1] == true)
        //s[i] != s[j], dp[i][j] = false;
        // j ==i, dp[i][i] = true; 
        if (s == "")
            return "";
        string strTemp="";
        for (int i = 0; i < s.length(); i++) {
            strTemp += s[i];
            strTemp += "#";
        }
        strTemp = strTemp.substr(0, strTemp.length()-1);
        cout << strTemp << endl;
        int n = strTemp.length();
        int **dp = new int*[n];
        for (int i = 0; i < n; i++) {
            dp[i] = new int[n];
            dp[i][i] = true;
            for (int j = i-1; j>=0; j--)
                dp[i][j] = false;
        }
        int res = 1;
        int startIndex = 0, endIndex=0;
        for (int i = n-1; i>=0; i--) {
            for (int j = i+1; j <n; j++) {
                if (strTemp[i] == strTemp[j]) {
                    if (dp[i+1][j-1] == true) {
                        dp[i][j] = true;
                        int relRes;
                        if (strTemp[i] == '#') {
                            relRes = j-i-1;
                        } else {
                            relRes = j-i+1;
                        }
                        if (relRes > res) {
                            startIndex = i;
                            endIndex = j;
                            res = relRes;
                        }
                        
                    } 
                    else
                        dp[i][j] = false;
                } else
                    dp[i][j] = false;
                //cout << i << " " << j << " " << dp[i][j] << endl;
            }
        }
        string resStr="";
        for (int i = startIndex; i <= endIndex; i++) {
            if (strTemp[i] != '#')
                resStr += strTemp[i];
        }
        return resStr;
    }
};
