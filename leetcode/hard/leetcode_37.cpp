class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        //假设只有唯一解答
        //这个一个算法简单，但是逻辑和代码比较复杂的题目
        backtracking(board, 0 , 0);

    }

    bool backtracking(vector<vector<char>>& board, int x, int y) {
        //找到第一个., 然后填入数字，继续dfs，直到没有.
        int r = 9;
        int c = 9;
        if (y == c) {
            return backtracking(board, x+1, 0);
        }
        if (x == r) {
            return true; //所有的位置都放完了
        }
        for (int i = x; i < r; i++) {
            for (int j = y; j < c; j++) {
                if (board[i][j] != '.')
                    return backtracking(board,i, j+1);
                for (char k = '1'; k <= '9'; k++) {
                    if (isValid(board, i, j, k)) {
                        board[i][j] = k;
                        if(backtracking(board, i, j+1)) {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                }
                return false; //关键在于语义，在这个位置是否可以放置元素，如果放置任何一个元素都不行，返回false；如果可以，换下一个元素
            }
        }
        return false;
    }

    bool isValid(vector<vector<char>> board, int x, int y, char c) {
        //x行，c只能有一个
        for (int i = 0; i < 9; i++) {
            if (board[x][i] == c)
                return false;
        }
        for (int i = 0; i < 9; i++) {
            if (board[i][y] == c)
                return false;
        }
        int startx = x/3*3;
        int starty = y/3*3;
        for (int i = 0; i  < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[startx+i][starty+j] == c)
                    return false;
            }
        }
        return true;
    }
};
