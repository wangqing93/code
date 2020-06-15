class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int x = 1;
        int y = 2;
        int t;
        for (int i = 3; i <= n; i++) {
            t = x;
            x = y;
            y = x + t;
        }
        return y;
    }
};
