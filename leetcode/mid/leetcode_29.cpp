#include <iostream>

using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483648
class Solution {
public:
    int divide(int dividend_ori, int divisor_ori) {  // A/B
        if (dividend_ori == 0)
            return 0;
        if ((dividend_ori == INT_MIN && divisor_ori == -1))
            return INT_MAX;
        unsigned int dividend = abs(dividend_ori);
        unsigned int divisor = abs(divisor_ori);
        int negativeFlag = 1;
        if ((dividend_ori < 0 && divisor_ori > 0) || (dividend_ori > 0 && divisor_ori < 0))
            negativeFlag = -1;
        //cout << dividend << " " << divisor << endl;
        long long res = 0;
        long long temp;
        long long midres;
        while(dividend >= divisor)
        {
            temp = divisor;
            midres = 1;
            while ((temp <<= 1)<= dividend)
            {
                midres <<= 1;
                //cout << temp << endl;
            }

            //cout << dividend << " " << temp << " " << res <<" " << midres << endl;
            dividend -= (temp>>1);
            res+=midres;
            //cout << dividend << " " << divisor << endl;
        }
        return negativeFlag == -1 ? -res:res;
    }
};

int main()
{
    Solution  test;
    cout << test.divide(-2147483648,1);
    cout << "Hello world!" << endl;
    return 0;
}
