class Solution {
public:
    // 最暴力的用法，46/52个测试例子，n平方的复杂度，又是一个数学题
    /*int maxScoreSightseeingPair(vector<int>& A) {
        int n = A.size();
        int maxV = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (A[i]+A[j]+i-j > maxV) {
                    maxV = A[i]+A[j]+i-j;
                }
            }
        }
        return maxV;
    }*/
    //优化想5min，窗口问题距离越远值越小，如果两个数相邻，数值增大超过1，这个值就是递增的
    //节点数5万个，每个位置的值1000，可以空间复杂度换时间复杂度
    //这个题目太巧妙了，变量集中化 A[i]+i, A[j]-j, 相当于A[i]+i在j-1的最大值
    int maxScoreSightseeingPair(vector<int>& A) { 
        int maxAdd = INT_MIN;
        int maxRes = INT_MIN;

        maxAdd = A[0];
        for (int j = 1; j < A.size(); j++) {
            if (maxRes < maxAdd + A[j]-j) {
                maxRes = maxAdd + A[j]-j;
            }
            maxAdd = max(maxAdd, A[j]+j);
        }
        return maxRes;
    }

};
