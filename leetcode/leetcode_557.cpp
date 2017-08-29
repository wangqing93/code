#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res, temp;
        for (int i = 0 ; i < s.length(); i++)
        {
            if (s.at(i) == ' ')
            {
                for (int j = temp.length()-1; j >= 0; j++)
                    res += temp.at(j);
                res+=" ";
                temp="";
            } else
                temp += s.at(i);
        }
        return res;
    }
};
