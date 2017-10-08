#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        if (m == 0)
            return 1;
        int n = dungeon[0].size();
        vector<vector<int>> dp;
        for (int i = 0; i < m; i++) {
            vector<int> t;
            for (int j = 0; j < n; j++) {
                t.push_back(1);
            }
            dp.push_back(t);
        }
        dp[m-1][n-1] = max(1-dungeon[m-1][n-1], 1);
        for (int i = n-2; i >= 0; i--) {
            dp[m-1][i] = max(dp[m-1][i+1]-dungeon[m-1][i], 1);
        }
        for (int i = m-2; i >= 0; i--) {
            dp[i][n-1] = max(dp[i+1][n-1]-dungeon[i][n-1], 1);
        }
        for (int i = m-2; i >= 0; i--) {
            for (int j = n-2; j >= 0; j--) {
                dp[i][j] = min(max(dp[i+1][j]-dungeon[i][j],1), max(dp[i][j+1]-dungeon[i][j], 1));
            }
        }
        return dp[0][0];
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
