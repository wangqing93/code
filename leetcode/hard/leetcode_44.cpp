#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        int i = 0, j = 0, marki, markj;
        bool flag = false;
        while (i < m && (flag == true || j < n))
        {
            if (s[i] == p[j] || p[j] == '?')
            {
                i++;
                j++;
            }
            else if (p[j] == '*')
            {
                if (j == n-1)
                    return true;
                flag = true;
                marki = i;
                markj = ++j;  // first no match
            }
            else
            {
                if (flag == false)
                    return false;
                i = ++marki;
                j = markj;
            }
        }
        while (j < n && p[j] == '*')
        {
                j++;
        }
        return (i==m && j==n);
    }
};

int main()
{
    Solution test;
    cout << test.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba","a*******b");
    //cout << "Hello world!" << endl;
    return 0;
}
