#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> keys;
int mt[6];
int res[6];

int t[6];
int keyt;

int middis;

int caltimes(int a[6])
{
    return ((a[0]*10+a[1])*60 + (a[2]*10+a[3]))*60 + a[4]*10+a[5];
}


void dfs(int x)
{
    if (x == 6)
    {
        int x1 = mt[0]*10+mt[1];
        int x2 = mt[2]*10+mt[3];
        int x3 = mt[4]*10+mt[5];
        if (x1 > 23 || x2 > 59 || x3 > 59) return;
        int temp = caltimes(mt);
        int dis = temp-keyt;
        if (dis <= 0) dis += 24*3600;
        if (middis == -1 || dis < middis)
        {
            //cout << middis << " " << dis  << " " << keyt << endl;
            for (int i = 0; i < 6; i++)
            {
                res[i] = mt[i];
                //cout << res[i] << " ";
            }
            //cout << endl;
            middis = dis;
        }
        return;
    }

    for (int i = 0; i < keys.size(); i++)
    {
        mt[x] = keys[i];
        dfs(x+1);
    }

}
void  nextCloseTime()
{
    keys.clear();
    bool flag = true;
    for (int i = 0; i < 6; i++)
        keys.push_back(t[i]);
    sort(keys.begin(), keys.end());
    keys.erase(unique(keys.begin(), keys.end()), keys.end());

    /*for (int i = 0; i < keys.size(); i++)
        cout << keys[i] << " " ;
    cout << endl;*/
    keyt = caltimes(t);
    middis = -1;
    dfs(0);
    cout << res[0] << res[1] << ":" << res[2] << res[3] << ":" << res[4] << res[5] << endl;
}
int main()
{
    int nums;
    cin >> nums;
    for (int i = 0; i < nums; i++)
    {
        scanf("%d:%d:%d", &t[0], &t[2], &t[4]);
        t[1] = t[0]%10;
        t[0] = t[0]/10;
        t[3] = t[2]%10;
        t[2] = t[2]/10;
        t[5] = t[4]%10;
        t[4] = t[4]/10;
        nextCloseTime();
    }
    return 0;
}
