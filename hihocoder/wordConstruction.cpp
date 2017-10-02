#include <iostream>
#include <vector>

using namespace std;

int A[45][45];
vector<int> SC[26];

int C[45];


int main()
{
    int nums;
    cin >> nums;
    string s;
    vector<string> oristr;
    for (int i = 0; i < nums; i++)
    {
        cin >> s;
        oristr.push_back(s);
        for(int j = 0; j < s.length(); j++)
            SC[s[j]-'a'].push_back(i);
    }
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < SC[i].size(); j++)
        {
            for (int k = j; k < SC[i].size(); k++)
            {
                A[SC[i][j]][SC[i][k]] = 1;
                A[SC[i][k]][SC[i][j]] = 1;
                //cout << SC[i][j] <<" " << SC[i][k] << endl;
            }

        }
    }
    for (int i = 0; i < nums; i++)
    {
        C[i] = 0;
        for (int j = 0; j < nums; j++)
        {
            //cout << A[i][j] << " ";
            if (A[i][j] == 1)
                C[i]++;
        }
        //cout << endl;
    }
    int res;
    while(true)
    {
        bool flag = true;
        res = 0;
        /*for (int  i = 0; i < nums; i++)
        {
            cout << C[i] << " " ;
        }*/
        for (int  i = 0; i < nums; i++)
        {
            //cout << C[i] << " " ;
            if (C[i] > 1)
            {
                flag = false;
                break;
            }
            if (C[i] == 1)
                res++;
        }
        //cout << endl;
        if (flag == true)
            break;
        // find c[i] max
        int maxStrIndex = 45, maxDegree = 0;
        for (int i = 0; i < nums; i++)
        {
            if (C[i] > maxDegree)
            {
                maxDegree = C[i];
                maxStrIndex = i;
            }
        }
        //cout << oristr[maxStrIndex] << endl;
        for (int i = 0; i < nums; i++)
        {
            if (A[maxStrIndex][i] == 1)
            {
                A[maxStrIndex][i] = 0;
                A[i][maxStrIndex] = 0;
                C[i]--;
                C[maxStrIndex]--;
            }
        }
        C[maxStrIndex]++;
    }
    cout << res << endl;
    return 0;
}
