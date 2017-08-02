#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++)
        {
            res += ((int)(s.at(i))-64);
            if (i < s.length()-1)
                res *= 26;
        }
        return res;
    }
};
