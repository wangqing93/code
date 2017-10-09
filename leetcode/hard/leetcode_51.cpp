#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    vector<vector<int>> mark;
    vector<vector<string>> res;
    int nn;
    vector<vector<string>> solveNQueens(int n) {
        for (int i = 0; i < n; i++) {
            vector<int> t;
            for (int j = 0; j < n; j++) {
                t.push_back(0);
            }
            mark.push_back(t);
        }
        nn = n;
        putqueen(0);
        return res;
    }
    vector<string> getRes()
    {
        vector<string> res;
        string str;
        for (int i = 0; i < nn; i++) {
            str="";
            for (int j = 0; j < nn; j++) {
                if (mark[i][j] == 0)
                    str+=".";
                else
                    str+="Q";
            }
            res.push_back(str);
        }
        return res;
    }
    bool judge(int x, int y) {
        for (int k = 0; k < x; k++) {
            if (mark[k][y] == 1)
                return false;
        }
        for (int j = 0; j < x; j++) {
            for (int k = 0; k < nn; k++) {
                if (mark[j][k] == 1) {
                    if (abs(x-j) == abs(y-k))
                        return false;
                }
            }
        }
        return true;
    }
    void putqueen(int x) // x row[0,n-1]
    {
        if (x == nn) {
            vector<string> midres = getRes();
            res.push_back(midres);
            return;
        }
        for (int y = 0; y < nn; y++)
        {
            if (judge(x, y)) {
                mark[x][y] = 1;
                putqueen(x+1);
                mark[x][y] = 0;
            }
        }
    }
};

int main()
{
    Solution t;
    vector<vector<string>> res = t.solveNQueens(4);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << endl;
        }
        cout << endl;
    }
    cout << "Hello world!" << endl;
    return 0;
}
