class Solution {
public:
    bool isMatch(string s, string p) {
        //使用回溯法难以debug，然后我参考discuss果断弃疗，采用动态规划，容易理解，而且简单
        //dp[i][j] 表示s[i] 是否可以匹配 p[j]  
        //p[j] == '*',  匹配零个或者多个前面的元素
        //s[i] != p[j-1] ,   不等于前面的那就不用匹配了， dp[i][j] = dp[i][j-2]
        //s[i] == p[j-1], 可以匹配那就可能匹配0个，匹配1个，或者匹配多个
        //--匹配0个   dp[i][j] = dp[i][j-2]  不匹配，直接跳过a*
        //--匹配1个  dp[i][j] = dp[i][j-1]  只匹配一次，就跳过了
        //--匹配多个 dp[i][j] = dp[i-1][j]  匹配一个少一个，继续匹配
        //p[j] == '.', dp[i][j] = dp[i-1][j-1]
        //p[j] == 其他字符, 
        //s[i]！=p[j]  dp[i][j]=0   默认就是false，所以可以不用赋值鸟
        //s[i]==p[j] 最普通的匹配，dp[i][j] = dp[i-1][j-1]
        //既然是动态规划，初始值就很重要了

        vector<vector<bool> > dp;
        int slen = s.length();
        int plen = p.length();
        for (int i = 0; i < slen+1; i++) {
            vector<bool> oneDp;
            for (int j = 0; j < plen+1; j++) {
                oneDp.push_back(false);
            }
            dp.push_back(oneDp);
        }
        //dp[i][j] 表示s的前i个是否能被p的前j个匹配
        //开始初始化
        dp[0][0] = true;
        for (int i = 1; i < slen+1; i++){
            dp[i][0] = false; //只要s有就是false，因为p啥都没有
        }

        for (int j = 1; j < plen; j++) {
            //s啥都没有，但是p呢，如果是*就棒呆了，因为*可以不匹配,*是连着前面的一个字符
            if (p[j] == '*' && dp[0][j-1])
                dp[0][j+1] = true;  // dp和p以及s的index差1
        }

        for (int i = 0; i < slen; i++) {
            for (int j = 0; j < plen; j++) {
                //只有*出现了-2， 证明*前面至少有一个字符，否则这个p是不合格的字符串
                //cout << "i:" << i <<" j:" << j <<endl; 
                if (p[j] == '*') {
                    // 等于. 就相当于s[i] == p[j-1]
                    if (s[i] != p[j-1] && p[j-1] != '.') {
                         dp[i+1][j+1] = dp[i+1][j-1];
                    } else {
                        dp[i+1][j+1] = dp[i+1][j-1] || dp[i+1][j] || dp[i][j+1];
                    }   
                } else if (p[j] == '.') {
                    dp[i+1][j+1] = dp[i][j];
                } else {
                    if (s[i] == p[j]) {
                            dp[i+1][j+1] = dp[i][j];
                    }
                }
            }
        }
        return dp[slen][plen];
    }
};
