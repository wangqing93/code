#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//https://hihocoder.com/problemset/problem/1595?sid=1202122
#define MAX_INT 2147483647
vector<int> data;

int getSeg(int start, int K)
{
    //cout << start << " " << K << " " << endl;
    if (K == 1)
        return data[data.size()-1]- data[start];
    int minV = MAX_INT;
    for (int i = start; i <= data.size()-K; i++)
    {
        int res = data[i]- data[start] + getSeg(i+1, K-1);
        //cout << i << " " << start << " " << K <<" " << res <<endl;
        if (minV > res)
            minV = res;
    }
    return minV;
}

int main()
{
    int n, k, temp;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        data.push_back(temp);
    }
    sort(data.begin(), data.end());
    for (int i = n-1; i >0 ; i--)
        data[i] = data[i]-data[i-1];
    sort(data.begin()+1, data.end());
    int res = 0;
    for (int i = 1; i <= n-k; i++)   //later k , before 1
        res += data[i];
    cout << res << endl;
    //cout << getSeg(0, k) << endl;
    return 0;
}
