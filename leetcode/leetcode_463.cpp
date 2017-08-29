#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ylen = grid.size(); //1
        vector<int> temp = grid[0];
        int xlen = temp.size(); //2
        int res = 0;
        for (int j = 0; j < xlen; j++)
        {
            if (grid[0][j] == 1)
                    res++;
            if (grid[ylen-1][j] == 1)
                    res++;
        }
        for (int i = 1; i < ylen; i++)
        {
            for (int j = 0; j < xlen; j++)
            {
                if (grid[i-1][j]^grid[i][j])
                    res++;
            }
        }
        for (int j = 0; j < ylen; j++)
        {
            if (grid[j][0] == 1)
                res++;
            if (grid[j][xlen-1] == 1)
                res++;
        }
        for (int i = 1; i < xlen; i++)
        {
            for (int j = 0; j < ylen; j++)
            {
                if (grid[j][i-1]^grid[j][i])
                    res++;
            }
        }
        return  res;

    }
};
