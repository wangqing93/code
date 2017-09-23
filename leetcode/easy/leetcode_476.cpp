#include <iostream>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int temp = 0xffffffff;
        while (temp & num)
            temp <<= 1;
        return ~num & ~temp;
    }
};
