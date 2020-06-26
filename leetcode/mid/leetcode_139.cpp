class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //其实就是wordDict里面的单词多次组合，能不能组合成s
        //dp[i][j] 表示[i,j]是否可以用wordDict组成，但是由小及大，i和j都变化的话有点困难
        //dp[i]可以由比它小的index过度过来  dp[i] =  true, if (dp[j]=true , s(j+1, i) in wordDict)
        unordered_map<string, bool> mark;
        for (int  i = 0; i < wordDict.size(); i++) {
            if (!mark.count(wordDict[i]))
                mark[wordDict[i]] = true;
        }
        bool* dp = new bool[s.length()+1];
        dp[0] = true;
        for (int i = 0 ; i < s.length(); i++) {
              // dp[i+1],表示s[0,i+1)是否可以被组成
            bool flag = false;
            for (int j = 0; j <= i; j++) {
                if (dp[j] && mark.count(s.substr(j,i-j+1))) {
                    flag = true;
                    break;
                }
            }
            dp[i+1] = flag;
            //cout << i+1 << " "  << dp[i+1] << endl;
        }
        return dp[s.length()];

    }
};
