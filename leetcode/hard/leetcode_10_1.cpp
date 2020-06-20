class Solution {
public:
    int** mark;
    bool isMatch(string s, string p) {
        mark = new int*[s.length()+1];
        for (int i = 0; i <= s.length(); i++)
            mark[i] = new int[p.length()+1];
        for (int i = 0; i <= s.length(); i++) {
            for (int j = 0; j <= p.length(); j++) {
                mark[i][j] = -1;
            }
        }
        return testMatch3(s,p,0,0);
    }
    bool testMatch3(string s, string p, int i, int j) {
        //cout << s << " " << p << " " << i << " " << j << endl;
        if (j>=p.length()){
            return i>=s.length()?true:false;
        }
        //s为空，不能直接返回false，因为p有可能不匹配
        if (mark[i][j] != -1)
            return mark[i][j]==0?false:true;
        bool curMatch = (i==s.length()?false:(p[j] == '.' || s[i] == p[j]));
        bool res;
        if (j <= p.length()-2 && p[j+1] == '*') {
            //不匹配前面的字符和匹配一次
            res = testMatch3(s, p, i, j+2) || 
            (curMatch && testMatch3(s, p, i+1, j)); 
        }
        else 
            res = curMatch && testMatch3(s, p, i+1, j+1);
        mark[i][j] = (res==true?1:0);    
        return res;
    }
};
