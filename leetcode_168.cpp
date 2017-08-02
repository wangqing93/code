#include <iostream>
#include <string>
#include <stdio.h>


using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string res="";
        string res1="";
        int temp;
        while(n > 0)
        {
            temp = n%26==0?26:n%26;
            res.push_back((char)(64 + temp));
            n = (n-temp)/26;

        }
        for (int i = res.length()-1; i > -1; i--)
            res1.push_back(res[i]);
        return res1;
    }
};
