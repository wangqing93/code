#include <iostream>
#include <vector>


using namespace std;

int tw[13];
vector<int> twr[13];
int res;
void addEdge(int i, int j)
{
    twr[i].push_back(j);
    twr[j].push_back(i);
}

int a[5];
int fs[5];
int con[5];

void dfs(int x)
{
    if (x == 5)
    {
        int midres = 0;
        for (int i = 0; i < 13; i++)
        {
            if (tw[i] != -1)
            {
                int fs1=0, con1=0;
                for (int j = 0; j <twr[i].size(); j++)
                {
                    if (tw[twr[i][j]] != -1)
                    {
                        int nindex = tw[twr[i][j]];
                        fs1++;
                        con1 |= 1 << a[nindex];   // kind
                    }
                }
                if (fs1 < fs[tw[i]])
                    continue;
                if ((con1 & con[tw[i]]) != con[tw[i]])
                    continue;
                midres++;
            }
        }
        if (midres > res)
        {
            res = midres;
            /*for (int i = 0; i < 13; i++)
                cout << tw[i] << " ";
            cout << endl;*/
        }

        return;
    }
    for (int i = 0; i < 13; i++)
    {
        if (tw[i] == -1)
        {
            tw[i] = x;
            dfs(x+1);
            tw[i] = -1;
        }
    }
}

int main()
{
    addEdge(0,2);//
    addEdge(0,3);//
    addEdge(1,2);//
    addEdge(2,3);//
    addEdge(3,4);//
    addEdge(1,5);//
    addEdge(2,5);//
    addEdge(2,6);//
    addEdge(3,6);//
    addEdge(3,7);//
    addEdge(4,7);//
    addEdge(5,6);//
    addEdge(6,7);//
    addEdge(5,8);//
    addEdge(5,9);//
    addEdge(6,9);//
    addEdge(6,10);//
    addEdge(7,10);//
    addEdge(7,11);//
    addEdge(8,9);//
    addEdge(9,10);//
    addEdge(10,11);//
    addEdge(9,12);//
    addEdge(10,12);//

    int tsn, temp;
    cin >> tsn;
    for (int i = 0; i < tsn; i++)
    {
        for (int j = 0; j <13; j++)
            tw[j] = -1;
        for (int j = 0; j < 5; j++)
        {
            cin >> a[j] >> fs[j];
            con[j] = 0;
            for (int k = 0; k < 6; k++)
            {
                cin >> temp;
                if (temp == 1)
                    con[j] |= 1 << k;
            }
        }
        res = 0;
        dfs(0);
        cout << res << endl;
    }
    return 0;
}
