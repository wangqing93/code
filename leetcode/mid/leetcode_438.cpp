class Solution {
public:
    //方案1
    /*vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int n = p.length();
        if (n > s.length())
            return res;
        int* cNum = new int[26];
        for (int i = 0; i < 26; i++) {
            cNum[i] = 0;
        }
        for (int i = 0; i < p.length(); i++) {
            cNum[int(p[i]-'a')]++;
        }
        for (int  i = 0; i < s.length()-n+1; i++) {
            string checkStr = s.substr(i, n);
            int* cShouldNum = new int[26];
            for (int k = 0; k < 26; k++) {
                cShouldNum[k] = cNum[k];
            }
            bool flag = true;
            for (int j = 0; j < checkStr.length(); j++) {
                if (cShouldNum[int(checkStr[j]-'a')] > 0)
                    cShouldNum[int(checkStr[j]-'a')]--;
                else {
                    flag = false;
                    break;
                }
            }
            if (flag)
                res.push_back(i);
        }
        return res;
    }*/

    //方案2
    vector<int> findAnagrams(string s, string p) {
        //经典的窗口题目，答案是每一种情况的left索引
        unordered_map<char, int> target;
        unordered_map<char, int> windows;
        for (int i = 0; i < p.length(); i++) {
            if (target.count(p[i])) {
                target[p[i]]++;
            } else {
                target.insert(make_pair(p[i], 1));
                windows.insert(make_pair(p[i], 0));
            }
        }

        int l = 0, r = 0;
        vector<int> res;
        int validNum = 0;
        while (r < s.length()) {
            char t = s[r];
            if (target.count(t)) {
                windows[t]++;
                if (windows[t] == target[t]) {
                    validNum++;
                }
            }

            while (r-l+1 >= p.size()) {
                if (validNum == target.size()) {
                    res.push_back(l);
                }
                char t1 = s[l];
                if (target.count(t1)) {
                    if (windows[t1] == target[t1])
                        validNum--;
                    windows[t1]--;
                }
                l++;
            }
            r++;
        }
        return res;
    }
};
