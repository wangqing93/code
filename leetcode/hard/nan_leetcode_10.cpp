#include <iostream>
#include <string>


using namespace std;

class Solution {
public:
    bool isMatch(string s, string p)
    {
        if (p.length() == 0)
        {
            if (s.length() == 0)
                return true;
            else
                return false;
        }
        if (p.length() == 1)
        {
            if (s.length() == 1 && p.substr(0,1) == ".")
                return true;
            else if (s.length() == 1 && p[0] == s[0])
                return true;
            else
                return false;
        }
        if (p.substr(1,1) != "*")
        {
            if (s.length() == 0)
                return false;
            if (p.substr(0,1) == "." || s[0] == p[0])
                return isMatch(s.substr(1,s.length()-1), p.substr(1,p.length()-1));
            else
                return false;
        } else
        {
            if (s.length() == 0)
            {
                return isMatch(s, p.substr(2,p.length()-2));
            }
            if (p.substr(0,1) == "." || p[0] == s[0])
                return isMatch(s.substr(1,s.length()-1), p) || isMatch(s, p.substr(2,p.length()-2));
            else
                return isMatch(s, p.substr(2,p.length()-2));
        }
    }
};
int main()
{
    string s,p;
    Solution test;
    while(true)
    {
        s="";
        cin >> p;
        cout << test.isMatch(s, p) << endl;
    }
    cout << "Hello world!" << endl;
    return 0;
}
