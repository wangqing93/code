#include <iostream>

using namespace std;

#define INI_MAX 2147483647
#define INI_MIN -2147483648
class Solution {
public:
    bool judgeNum(char x) {
        if (x >= '0' && x <= '9')
            return true;
        return false;
    }
    int myAtoi(string str) {
        if (str.length() == 0)
            return 0;
        bool positive = true;
        int start_index = 0;
        while(!judgeNum(str[start_index]) && str[start_index]==' ')
            start_index++;
        int signal_num = 0;
        while (!judgeNum(str[start_index]) && (str[start_index] == '-' || str[start_index] == '+'))
        {
            if (str[start_index] == '-')
                positive = !positive;
            signal_num ++;
            start_index++;
        }
        long long res = 0;
        if (signal_num > 1)
            return res;
        while(judgeNum(str[start_index]) && str[start_index]=='0')
            start_index++;
        for (int i = start_index; judgeNum(str[i]) && i < str.length(); i++) {
            res = res*10+str[i]-'0';
            if (res > INI_MAX && positive)
                return INI_MAX;
            if (!positive && res > -INI_MIN)
                return INI_MIN;
        }
        return positive == true ? res: 0-res;
    }
};

int main()
{
    Solution s;
    cout << s.myAtoi("+-28") << endl;
    cout << s.myAtoi("1") << endl;
    cout << s.myAtoi("   010") << endl;
    cout << s.myAtoi("     +004500") << endl;
    cout << s.myAtoi("  -0012a42") << endl;
    cout << s.myAtoi("2147483648") << endl;
    cout << s.myAtoi("-2147483648") << endl;
    cout << s.myAtoi("-92147483648") << endl;
    cout << s.myAtoi("9223372036854775809") << endl;
    return 0;
}
