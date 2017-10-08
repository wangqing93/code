#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;
struct pos
{
    int x;
    int y;
    pos(int x1, int y1) {
        x = x1;
        y = y1;
    }
};


class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};

    void dfs(int x, int y, int& m, int& n, vector<vector<int>>& grid, vector<vector<bool>>& visited, int& max_area, int& temp_area)
    {
        //return condition
        if (x >= m || x <0 || y <0 || y >= n || visited[x][y] || grid[x][y]==0)
        {
            max_area = max(temp_area, max_area);
            return;
        }
        //dfs all condition
        temp_area++;
        visited[x][y]=true;
        for (int i = 0; i < 4; i++)
        {
            dfs(x+dx[i], y+dy[i], m, n, grid, visited, max_area, temp_area);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        int max_area = 0, temp_area;
        vector<vector<bool>> visited;
        for (int i = 0; i < m; i++) {
            vector<bool> temp;
            for (int j = 0; j < n; j++) {
                temp.push_back(false);
            }
            visited.push_back(temp);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                temp_area = 0;
                dfs(i,j,m,n,grid,visited,max_area,temp_area);
            }
        }
        return max_area;
    }

};

int main()
{
    int A[4][5] = {{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
    vector<vector<int> > datas;
    for (int i =0; i < 4; i++)
    {
        vector<int> temp;
        for (int j = 0; j < 5; j++)
        {
            temp.push_back(A[i][j]);
        }
        datas.push_back(temp);
    }
    Solution a;
    cout << a.maxAreaOfIsland(datas);
    //cout << "Hello world!" << endl;
    return 0;
}
