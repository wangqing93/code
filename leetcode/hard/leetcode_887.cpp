class Solution {
public:
    /*
    int superEggDrop(int K, int N) {
        return tryEgg(K, N);
    }


    int tryEgg(int eggNum, int floorNum) {
        int res = INT_MAX;
        if (eggNum == 0 || floorNum == 0)
            return 0;
        if (eggNum == 1)
            return floorNum; //只剩下一个鸡蛋，每层都要扔
        for (int i = 1; i  <=floorNum; i++)  {
            res = min(res, max(tryEgg(eggNum-1, i-1), tryEgg(eggNum, floorNum-i))+1);  //碎了就往下和没碎往上两种情况的max
        }
        return res;
    }*/

    int superEggDrop(int K, int N) {
        // dp[i][j] = dp[i-1][j-1]
        //如果我们可以做 T次操作，而且有 K 个鸡蛋，那么我们能找到答案的最高的楼层N = dp[T][K]
        //扔了一个鸡蛋：如果碎了，这一层下方有这么多楼层dp[T-1][k-1]；如果没有碎，这一层上方有dp[T-1][K]
        //dp[T][K] = 1 + dp[T-1][k-1] + dp[T-1][k]
        //T从1-N， 当dp[T][K] == N，返回T
        //dp[0][k] = 0;  dp[t][1] = t;
        int **dp = new int*[N+1];
        for (int i = 0; i <= N; i++) {
            dp[i] = new int[K+1];
            dp[i][0] = 0;
        }
        for (int i = 1; i <= K; i++) {
            dp[0][i] = 0;
            dp[1][i] = 1; // 0个鸡蛋，一次操作也没用
        }
            
        for (int i = 2; i <= N; i++) {
            for (int j = 1; j <= K; j++) {
                dp[i][j] = 1 + dp[i-1][j-1] + dp[i-1][j];
            }
            if (dp[i][K] >= N)
                return i;
        }
        return N;
    }
};
