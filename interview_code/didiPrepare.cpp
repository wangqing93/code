#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// find <= key maxRight
int binarySearch(vector<int> values, int key)
{
    sort(values.begin(), values.end());
    int left = 0, right = values.size()-1, mid;// [left, right]
    while (left <= right)
    {
        mid = (left+right)>>1;
        if (values[mid] > key)
            right = mid-1;
        else
            left = mid+1;
    }
    if (right >= 0 && right < values.size() && values[right] <= key)
        return right;
    else
        return -1;
}


//n个台阶，一次可以上1个或者2个，多少种， F(n) = F(n-1) + F(n-2)  F(1) = 1, F(2)=2, F(3)=3, F(4)=5
int methodNums(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    int pre = 2, prepre = 1, temp;
    for (int i = 3; i <= n; i++)
    {
        temp = pre + prepre;
        prepre = pre;
        pre = temp;
    }
    return pre;
}

int findOneNum(int n)
{
    int count = 0;
    while(n!=0)
    {
        if (n&1)
            count++;
        n = n >> 1;
    }
    return count;
}

struct node
{
    int x;
    int y;
    node(int xv, int yv)
    {
        x = xv;
        y = yv;
    }
};

void snakelikeOutput(vector<vector<int>> matrix)
{
    if (matrix.size() == 0)
        return;
    //check validity
    if (matrix[0].size() != matrix.size())
        return;
    int numIndex;
    vector<node> mark;
    mark.push_back(node(0,0));

    for (int i = 1; i < matrix.size(); i++)
    {
        if (i%2==1)
        {
            mark.push_back(node(i,0));
            mark.push_back(node(0,i));
        } else
        {
            mark.push_back(node(0,i));
            mark.push_back(node(i,0));
        }
    }
    for (int i = 1; i < matrix.size()-1; i++)
    {
        if ((i+matrix.size())%2==1)
        {
            mark.push_back(node(i,matrix.size()-1));
            mark.push_back(node(matrix.size()-1,i));
        } else
        {
             mark.push_back(node(matrix.size()-1,i));
             mark.push_back(node(i,matrix.size()-1));
        }
    }
    mark.push_back(node(matrix.size()-1, matrix.size()-1));
    for (int i = 0; i < mark.size(); i++)
    {
        //cout << mark[i].x << " " << mark[i].y << endl;
        if (i == 0 || i== mark.size()-1)
            cout << matrix[mark[i].x][mark[i].y] << endl;
        else
        {
            if (mark[i].x > mark[i+1].x)
            {
                for (int  j = 0; j <= mark[i].x - mark[i+1].x ; j++)
                    cout << matrix[mark[i].x-j][mark[i].y+j] << endl;
            }
            else
            {
                for (int  j = 0; j <= mark[i+1].x -mark[i].x; j++)
                    cout << matrix[mark[i].x+j][mark[i].y-j] << endl;
            }
            i = i+1;
        }
    }
}
// 5 8 zhao6

vector<vector<int>>  getmatrix(int n)
{
    vector<vector<int>> matrix;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            temp.push_back(i*n+j);
        }
        matrix.push_back(temp);
    }
    return matrix;
}
int main()
{
    /*vector<int> test;
    int c;
    for (int i = 0;i < 7; i++)
    {
        cin >> c;
        test.push_back(c);
    }
    cout << binarySearch(test, 6); // 2 3 5 6 6 6 9*/
    //cout << methodNums(4) << endl;
    //cout << findOneNum(2) << endl;
    //cout << findOneNum(3) << endl;
    vector<vector<int>> matrix = getmatrix(3);
    snakelikeOutput(matrix);
    //cout << "Hello world!" << endl;
    return 0;
}
