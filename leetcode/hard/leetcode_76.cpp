class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> target;
        unordered_map<char, int> windows;
        for (int i = 0 ; i < t.length(); i++) {
            if (target.count(t[i]) > 0)
                target[t[i]]++;
            else {
                target.insert(make_pair(t[i], 1));
                windows.insert(make_pair(t[i], 0));
            }
                
        }


        //从左到右遍历
        int l = 0, r = 0;   //l表示窗口的左边界，窗口从字符串左边会一直到右边
        int resL = 0, resR = s.size()-1;
        int minLengthRes = INT_MAX;
        int validCharNum = 0;
        while(r < s.size()) { //[l, r]
            char c = s[r];
            if (target.count(c)) {
                windows[c]++;
                if (windows[c] == target[c])
                    validCharNum++;
            }
            while (validCharNum == target.size()) {
                if (r-l < minLengthRes) {
                    resL = l;
                    resR = r;
                    minLengthRes = r -l;
                }
                char deleteC = s[l];
                l++;
                if (target.count(deleteC)) {
                    if (windows[deleteC] == target[deleteC])
                        validCharNum--;
                    windows[deleteC]--;
                }
            }
            //如果target里面没有c，直接扩充窗口就好了
            //如果target里面有c，这时候需要把c更新到windows【多了没关系】。更新之后观测windows是否满足target，满足了缩小窗口
            r++;
        }
        if (minLengthRes != INT_MAX)
            return s.substr(resL, resR-resL+1);
        return "";
    }
};
