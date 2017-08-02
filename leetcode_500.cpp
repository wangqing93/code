#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <ctype.h>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string temp = "QWERTYUIOP";
        unordered_map<char, int>  temp1;
        for (int i = 0; i < temp.length(); i++)
            temp1.insert(make_pair(temp.at(i), 1));
        temp = "ASDFGHJKL";
        for (int i = 0; i < temp.length(); i++)
            temp1.insert(make_pair(temp.at(i), 2));
        temp = "ZXCVBNM";
        for (int i = 0; i < temp.length(); i++)
            temp1.insert(make_pair(temp.at(i), 3));
        vector<string> res;
        for (int i = 0; i < words.size(); i++)
        {
            int mark = temp1[toupper(words[i].at(0))];
            bool flag = true;
            for (int j = 0; j < words[i].length(); j++)
            {
                if (mark != temp1[toupper(words[i].at(j))])
                {
                    flag = false;
                    break;
                }
            }
            if(flag == true)
                res.push_back(words[i]);
        }
        return res;
    }
};
