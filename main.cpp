#include <iostream>

using namespace std;


class Solution {
public:
    bool hasAlternatingBits(int n) {
        int i = n&1;
        while(n!=0)
        {
            if (i != (n&1))
            {
                return false;
            }
            i = 1 - i;
            n = n >> 1;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.hasAlternatingBits(7) << endl;
    return 0;
}
