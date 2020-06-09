class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> target;
        unordered_map<char, int> windows;
        int validNum = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (target.count(s1[i]))
                target[s1[i]]++;
            else {
                target.insert(make_pair(s1[i], 1));
                windows.insert(make_pair(s1[i], 0));
            }
        }

        int l = 0, r = 0;
        while(r < s2.size()) {
            char t = s2[r];
            //窗口数据更新
            if (windows.count(t)){
                windows[t]++;
                if (windows[t] == target[t]) {
                    validNum++;
                }
            }
            //窗口收缩，每次收缩之前都要检测值是不是正确，然后收缩更新窗口
            while(r-l+1 >= s1.size()) {
                if (validNum == target.size()) {
                    return true;
                }
                char t1 = s2[l];
                l++;
                if (windows.count(t1)) {
                    if (windows[t1] == target[t1])
                        validNum--;
                    windows[t1]--;
                }
            }
            r++;
        }
        return false;
    }
};
