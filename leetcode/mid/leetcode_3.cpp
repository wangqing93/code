class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>  mark;
        int start = 0;
        int max_len = 0;
        for (int i = 0; i < s.length(); i++) {
            if (mark.find(s[i]) == mark.end()) {
                mark[s[i]] = i;
            }   
            else {
               if ((i-start) > max_len) {
                   max_len = i - start;
               } 
                int temp = mark[s[i]];
                for (int j = start; j <= temp; j++)
                    mark.erase(s[j]);
                start = temp+1;
                mark[s[i]] = i;
            }
        }
        if ((s.length()-start) > max_len)
            return s.length()-start;
        return max_len;
    }
};