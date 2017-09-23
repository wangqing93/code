#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    int findLUSlength(string a, string b) {
        // a shorter string
        string temp;
        if (a.length() > b.length())
        {
            temp = a;
            a = b;
            b = temp;
        }
        for (int len = a.length(); len > 0; len--)
        {
            bool flag = true;
            for (int i = 0; i+len-1 < a.length(); i++)
            {
                temp = a.substr(i, len);
                if (b.find(temp) != -1)
                {
                    flag = false;
                    break;
                }
            }
            if (flag == true)
                return len;
        }
        return -1;
    }
};
