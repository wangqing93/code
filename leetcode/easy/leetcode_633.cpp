class Solution {
public:
//超时了
    /*bool judgeSquareSum(int c) {
        bool* dp = new bool[c+1];
        for (int i = 0; i <= c; i++) {
            dp[i] = false;
        }
        for (int j = 0; j*j <=c; j++) {
            dp[j*j] = true;
        }
        for (int j = 0; j*j <=c; j++) {
            if (dp[c-j*j])
                return true;
        }
        return false;
    }*/

    //费马
    bool judgeSquareSum(int c) {
        // Line 22: Char 31: runtime error: signed integer overflow: 46341 * 46341 cannot be represented in type 'int' (solution.cpp)
        for (long j = 0; (int)j*j <=c; j++) {
            int temp = c-j*j;
            double x  = sqrt(temp);
            if (x == (int)x)
                return true;
        }
        return false;
    }
};
