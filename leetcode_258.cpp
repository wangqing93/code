#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int x) {
        int res;
        if (x < 10)
            return x;
        while(x != 0)
        {
            res = (res + (x%10))%9;
            x/=10;
        }
		if (res == 0)
			return 9;
        return res;
    }
};
