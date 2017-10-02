#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>



using namespace std;

int dp[1003][1003][2];  //0 no choose;  1 choosed

int getRes(unordered_map<int, int> mark, vector<int> candidate, int m)
{
    int temp;
    dp[0][0][1] = mark[candidate[0]]; // from [0,0] choose 1
    dp[0][0][0] = 0; //no choose
    for (int i = 1; i < candidate.size(); i++)
    {
        dp[i][0][1] = max(mark[candidate[i]], dp[i-1][0][1]);
        dp[i][0][0] = mark[candidate[0]];  //0
    }
    for (int i = 0; i < m; i++)
    {
        dp[0][i][1] = mark[candidate[0]];
        dp[0][i][0] = 0;
    }
    for(int i = 1; i < candidate.size(); i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]);
            if (candidate[i] > candidate[i-1]+1)
                temp = dp[i-1][j-1][1];
            else
                temp = dp[i-1][j-1][0];
            dp[i][j][1] = max(dp[i-1][j-1][0], temp) + mark[candidate[i]];
        }
    }
    return max(dp[candidate.size()-1][m-1][0], dp[candidate.size()-1][m-1][1]);
}


int main()
{
    int n, m,v;
    unordered_map<int, int> mark;
    vector<int> candidate;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> v;
        if (mark.find(v) == mark.end())
        {
             mark.insert(make_pair(v,v));
             candidate.push_back(v);
        }
        else
            mark[v]+=v;
    }
    sort(candidate.begin(), candidate.end());
    cout << getRes(mark,candidate,m) << endl;
    return 0;
}
