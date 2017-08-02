#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int characs[26]={0};
        int fist[26]={-1};
        for (int i = 0; i < s.length(); i++)
        {
            if (characs[(int)s.at(i)-97] == 0)
                fist[(int)s.at(i)-97] = i;
            else
                fist[(int)s.at(i)-97] = s.length();
            characs[(int)s.at(i)-97]++;
        }
        int min_v = s.length();
        for (int i = 0; i < 26; i++)
        {
              if (fist[i] < min_v)
                    min_v = fist[i];
        }
        if (min_v == s.length())
            return -1;
        return min_v;
    }
};
