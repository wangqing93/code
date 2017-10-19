#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        //cout << s << endl;
        int A[26];
        for (int i = 0; i < 26; i++) {
            A[i] = 0;
        }

        for (int i = 0; i < s.length(); i++) {
            A[s[i]-'a']++;
        }

        unordered_map<int, int> mark;
        for (int i = 0; i < 26; i++) {
                //cout << A[i] << " ";
            if (A[i] < k && A[i] > 0)
                mark[i] = 1;
        }
        //cout << endl;

        if (mark.empty())
        {
            //cout << s << " " << s.length() << endl;
            return s.length();
        }

        int res = 0;
        int flag = false;
        int start;
        //cout << "split s:" << s << endl;
        for (int i = 0; i < s.length(); i++) {
            if (flag == false && mark.find(s[i]-'a') == mark.end()) {
                start = i;
                flag = true;
            }
            if (mark.find(s[i]-'a') != mark.end() && flag == true) {
                res = max(res, longestSubstring(s.substr(start, i-start), k));
                flag = false;
            }
        }
        if (flag)
            res = max(res, longestSubstring(s.substr(start, s.length()-start), k));
        return res;
    }
};

int main()
{
    Solution t;
    cout << t.longestSubstring("bbaaacbd", 3);
    cout << "Hello world!" << endl;
    return 0;
}
