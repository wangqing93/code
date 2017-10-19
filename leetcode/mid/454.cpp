#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int sum = 0;
        unordered_map<int, int> markAB;
        unordered_map<int, int> markCD;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                if (markAB.find(A[i]+B[j]) == markAB.end())
                    markAB[A[i]+B[j]]=1;
                else
                    markAB[A[i]+B[j]]++;
            }
        }
        for (int i = 0; i < C.size(); i++) {
            for (int j = 0; j < D.size(); j++) {
                if (markCD.find(C[i]+D[j]) == markCD.end())
                    markCD[C[i]+D[j]]=1;
                else
                    markCD[C[i]+D[j]]++;
            }
        }
        for (auto it = markAB.begin(); it != markAB.end(); ++it) {
            if (markCD.find(0-it->first) != markCD.end())
                sum += it->second * markCD[0-it->first];
        }
        return sum;
    }
    //n*n*n
    int fourSumCount1(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int sum = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                sum += twoSumCount(C, D, 0-A[i]-B[j]);
            }
        }
        return sum;
    }
    int twoSumCount(vector<int>& C, vector<int>& D, int sum) {
        unordered_map<int, int> mark;
        for (int i = 0; i < D.size(); i++) {
            if (mark.find(D[i]) == mark.end())
                mark[D[i]] = 1;
        }
        int res = 0;
        for (int i = 0;i < C.size(); i++) {
            if (mark.find(sum-C[i]) != mark.end())
                res++;
        }
        return res;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
