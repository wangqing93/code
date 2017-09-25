#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int possibleChanges(vector<int> changes)
{
    int A[10];
    for (int i = 0; i < 10; i++)
        A[i] = -1;
    for (int i = 0; i < changes.size(); i++)
        A[changes[i]] = 1;
    int minSum = -1;
    for (int i = 1; i < 10; i++)
    {
        if (A[i] == 1)
            continue;
        minSum = -1;
        for (int j = 1; j <= i/2; j++)
        {
            if (A[j] == -1 || A[i-j] == -1)
                continue;
            else
            {
                if (minSum > A[j]+A[i-j] || minSum == -1)
                    minSum = A[j]+A[i-j];
            }
        }
        if (minSum == -1)
            return -1;
        A[i] = minSum;
    }
    minSum = 0;
    for (int i = 1; i < 10; i++)
        minSum += A[i];
    return minSum;
}

vector<vector<int>>  generatePossible(int n)
{
    vector<vector<int>> res;
    return res;
}

vector<int> findOptimal(int n)
{
    int minSum = 10, temp;
    vector<int> optimal;
    vector<vector<int>> pos = generatePossible(n);
    for (int i = 0; i < pos.size(); i++)
    {
        temp = possibleChanges(pos[i]);
        if (minSum > temp)
        {
            minSum = temp;
            optimal = pos[i];
        }
    }
    return optimal;
}

void outputOptimal()
{
    for (int i = 1; i < 9; i++)
    {
        vector<int> res = findOptimal(i);
        cout << i << ": ";
        for (int j = 0; j < res.size(); j++)
            cout << res[j] << " ";
        cout << endl;
    }
}

int main()
{
    //outputOptimal();
    vector<int> test;
    test.push_back(1);
    test.push_back(3);
    test.push_back(5);
    cout << possibleChanges(test);
    cout << "Hello world!" << endl;
    return 0;
}
