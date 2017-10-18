#include <iostream>
#include <stdlib.h>
#include <queue>
#include <stdio.h>
#include <cstring>


using namespace std;

int m_x, m_y;
int b_x, b_y;
int e_x, e_y;
int xchange[4]={0,0,1,-1};
int ychange[4]={1,-1,0,0};

struct state {
    int mx,my,bx,by;
    state(int x, int y, int x1, int y1) {
        mx = x;
        my = y;
        bx = x1;
        by = y1;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    string s;
    char panel[n][m];
    int visited[n][m][n][m];
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            panel[i][j] = s[j];
            if (s[j] == 'S') {
               m_x = i;
               m_y = j;
            } else if (s[j] == '0') {
               b_x = i;
               b_y = j;
            } else if (s[j] == 'E') {
               e_x = i;
               e_y = j;
            }
        }
    }
    /*cout << m_x << " " << m_y << endl;
    cout << b_x << " " << b_y << endl;
    cout << e_x << " " << e_y << endl;*/

    visited[m_x][m_y][b_x][b_y] = 1;
    state t(m_x, m_y, b_x, b_y);
    queue<state> trace;
    trace.push(t);
    int res= -1;
    while(!trace.empty()) {
        state pos = trace.front();
        trace.pop();
        if (pos.bx == e_x && pos.by == e_y)
        {
            res = visited[pos.mx][pos.my][pos.bx][pos.by]-1;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int cur_mx = pos.mx + xchange[i], cur_my = pos.my + ychange[i];
            if (cur_mx < 0 || cur_mx >= n || cur_my < 0 || cur_my >= n || panel[cur_mx][cur_my]=='#')
                continue;
            if (cur_mx == pos.bx && cur_my == pos.by) {
                    //箱子和你一起走，所以要看箱子是不是符合能走的条件
                if (cur_mx+xchange[i] < 0 || cur_mx+xchange[i] >= n || cur_my+ychange[i] < 0 || cur_my+ychange[i] >= n || panel[cur_mx+xchange[i]][cur_my+ychange[i]]=='#')
                    continue;
                    //bfs到过的状态已经是最近的了
                if (visited[cur_mx][cur_my][cur_mx+xchange[i]][cur_my+ychange[i]])
                    continue;
                visited[cur_mx][cur_my][cur_mx+xchange[i]][cur_my+ychange[i]] = visited[pos.mx][pos.my][pos.bx][pos.by]+1;
                trace.push(state(cur_mx, cur_my, cur_mx+xchange[i], cur_my+ychange[i]));
            } else {
                //只有人在走
                if (visited[cur_mx][cur_my][pos.bx][pos.by])
                    continue;
                visited[cur_mx][cur_my][pos.bx][pos.by] = visited[pos.mx][pos.my][pos.bx][pos.by]+1;
                trace.push(state(cur_mx, cur_my, pos.bx, pos.by));
            }
        }
    }
    cout << res << endl;
    return 0;
}
