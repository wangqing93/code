class Solution {
public:
    bool isMatch(string s, string p) {
        //新学了一种方案，使用递归
        //cout << "isMatch: " << s << " ||||  " << p << endl;
        if (p==""){
            return s==""?true:false;
        }
        //s为空，不能直接返回false，因为p有可能不匹配
        bool curMatch = (s==""?false:(p[0] == '.' || s[0] == p[0]));
        if (p.length() >= 2 && p[1] == '*') {
            //不匹配前面的字符和匹配一次
            return isMatch(s, p.substr(2,p.length()-2)) || 
            (curMatch && isMatch(s.substr(1,s.length()-1), p)); 
        }
        else 
            return curMatch && isMatch(s.substr(1,s.length()-1), p.substr(1,p.length()-1));
    }
};
