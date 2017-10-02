#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

//https://hihocoder.com/problemset/problem/1601?sid=1202241

using namespace std;

int dp[1003][1003];

int getRes(unordered_map<int, int> mark, vector<int> candidate, int m)
{
    dp[0][1] = mark[candidate[0]];
    dp[1][1] = max(mark[candidate[0]], mark[candidate[1]]);
    if (candidate[1] > candidate[0]+1)
        dp[1][2] = mark[candidate[0]] + mark[candidate[1]];
    else
        dp[1][2] = dp[1][1];
    for (int j = 2; j <= m; j++)
    {

        dp[0][j] = dp[0][1]; // choose one only one member
        dp[1][j] = dp[1][2] ;//two member
    }
    for (int i = 2; i < candidate.size(); i++)
    {
        int temp = candidate[i] > candidate[i-1]+1?i-1:i-2;
        for (int j = 1; j <= m; j++)
        {
                dp[i][j] = max(dp[temp][j-1]+mark[candidate[i]], dp[i-1][j]);
        }
    }
    return dp[candidate.size()-1][m];
}

int getRes1(unordered_map<int, int> mark, vector<int> candidate, int m)
{
    dp[0][1]=mark[candidate[0]];

    for(int i=1;i<=m;++i)
        dp[0][i]=dp[0][1];
    dp[1][1]=max(mark[candidate[0]],mark[candidate[1]]);
    if(candidate[1]>candidate[0]+1)
        dp[1][2]=mark[candidate[0]]+mark[candidate[1]];
    for(int i=1;i<=m;++i)
        dp[1][i]=max(dp[1][i],dp[1][i-1]);
    for(int i=2;i<candidate.size();++i){
        int j=candidate[i]>candidate[i-1]+1?i-1:i-2;
        for(int k=1;k<=m;++k){
            dp[i][k]=max(dp[i-1][k],dp[j][k-1]+mark[candidate[i]]);
        }
    }
    return dp[candidate.size()-1][m];

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
    printf("%d\n", getRes(mark,candidate,m) );
    return 0;
}
