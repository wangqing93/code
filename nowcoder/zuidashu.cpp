class Solution {
public:
    /**
     *
     * @param s string字符串
     * @return int整型
     */
    int solve(string s) {
        // write code here
        int left = 0, right = 0;
        int maxRes = INT_MIN;
        string windows;
        //cout << " init" << endl;
        while (left < s.length() && !isValidFirst(s[left])) {
            left++;
        }
        if (left == s.length())
            return 0;
        windows = s[left];
        maxRes = StringHex2int(windows);
        //cout << " find left first" << endl;
        right = left+1;
        while(right < s.length()) {
            //cout << "find right: " << right << " " << windows << endl;
            if (isValid(s[right])) {
                windows += s[right];
                if (StringHex2int(windows) > maxRes) {
                    maxRes = StringHex2int(windows);
                    //cout << windows << " "  << maxRes << endl;
                }
                // update maxRes;
            } else {
                
                left = right+1;
                while (left < s.length() && !isValidFirst(s[left])) {
                    left++;
                }
                if (left == s.length())
                    break;
                if (StringHex2int(s.substr(left, 1)) > maxRes) {
                    maxRes = StringHex2int(s.substr(left, 1));
                }
                windows=s[left];
                right = left;
            }
            right++;
        }
        return maxRes;
    }
    
    bool isValid(char c) {
        if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))
            return true;
        return false;
    }
    
    bool isValidFirst(char c) {
        if ((c > '0' && c <= '9') || (c >= 'A' && c <= 'F'))
            return true;
        return false;
    }
    
    int StringHex2int(string s) {
        int res = 0;
        int x = 1;
        for (int i= 0; i < s.length(); i++) {
            res += Char2Hex(s[s.length()-1-i])*x;
            x*=16;
        }
        return res;
    }
    
    int Char2Hex(char c) {
        if (c >= '0' && c <= '9')
           return int(c-'0');
        else
            return int(c-'A')+10;
    }
};
//https://www.nowcoder.com/questionTerminal/ac72e27f34c94856bf62b19f949b8f36
