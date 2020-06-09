class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //依旧可以用窗口做，窗口里面的字符个数不超过1
        unordered_map<char, int> windows;
        int l = 0, r = 0;
        int res = 0;
        while (r < s.size()) {
            char t = s[r];
            //更新窗口
            if (windows.count(t)) {
                windows[t]++;
            } else {
                windows[t] = 1;
            }
            //滑动窗口是否要收缩，滑动窗口里面的都是满足条件的，不满足条件了就要搜索
            while (windows[t] > 1) {
                char t1 = s[l];
                windows[t1]--;
                l++;
            }
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};
