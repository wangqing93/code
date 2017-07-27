#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool judgeUpper(char temp)
    {
        if (temp >= 'A' && temp <= 'Z')
            return true;
        return false;
    }
    bool detectCapitalUse(string word) {
        if (word.length() < 2)
            return true;
        char first_str = word.at(0);
        char second_str = word.at(1);
        bool capital = false;
        if (judgeUpper(first_str))
        {
            if (judgeUpper(second_str))
                capital = true;
            else
                capital = false;
        } else if (!judgeUpper(second_str))
            capital = false;
        else
            return false;
        for (int i=2; i<word.length(); i++)
        {
            if (capital && !judgeUpper(word.at(i)))
                return false;
            if (!capital && judgeUpper(word.at(i)))
                return false;
        }
        return true;
    }
};
