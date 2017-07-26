#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> temp;
        if (x < 0)
            return false;
        if (x == 0)
            return true;
        while(x != 0)
        {
            temp.push_back(x%10);
            x/=10;
        }
        int len = temp.size();
        for (int i = 0; i < len/2; i++)
        {
            if (temp[i]!= temp[len-1-i])
                return false;
        }
        return true;
    }
};
