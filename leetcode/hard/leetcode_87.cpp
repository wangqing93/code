#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length())
            return false;
        if (s1 == s2)
            return true;
        int s1_count[26] = {0};
        int s2_count[26] = {0};
        for (int i = 0; i < s1.length(); i++)
        {
            s1_count[s1[i]-'a']++;
            s2_count[s2[i]-'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (s1_count[i] != s2_count[i])
                return false;
        }
        string s1_1, s1_2, s2_1, s2_2;
        for (int i = 1; i < s1.length(); i++)
        {
            s1_1 = s1.substr(0,i);
            s1_2 = s1.substr(i, s1.length()-i);
            s2_1 = s2.substr(0,i);
            s2_2 = s2.substr(i, s1.length()-i);
            if ((isScramble(s1_1, s2_1) && isScramble(s1_2, s2_2)) || (isScramble(s1_1, s2.substr(s1.length()-i))&&isScramble(s1_2, s2.substr(0, s1.length()-i))))
                return true;
        }
        return false;
    }
};

int main()
{
    Solution t;
    t.isScramble("ab", "ba");
    cout << "Hello world!" << endl;
    return 0;
}
