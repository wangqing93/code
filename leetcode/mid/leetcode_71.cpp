#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string simplifyPath(string s) {
    vector<string> mark;
    string temp= "", res="";
    for (int i = 0; i < s.length(); i++)
    {
       if (s.at(i) != '/')
            temp += s[i];
       else
        {
            if (temp != ".." && temp != "." && temp != "")
                mark.push_back(temp);
            if (temp == ".." && !mark.empty())
                mark.pop_back();
            temp = "";
        }

    }

    if (temp != ".." && temp != "." && temp != "")
        mark.push_back(temp);
    if (temp == ".." && !mark.empty())
        mark.pop_back();

    if (mark.size() == 0)
        res =  "/";
    else
    {
        for (int i = 0; i < mark.size(); i++)
        {
            res +="/";
            res += mark[i];
        }
    }
        return res;
    //  /a/.b/../../c//////b

    }
};