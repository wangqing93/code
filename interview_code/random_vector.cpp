#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <math.h>
#include <stdlib.h>

#define random(x)(rand()%x)
using namespace std;

void func(vector<int> nums, int times)
{
    int len = nums.size();
    int x, y;
    for (int i = 0; i < times; i++)
    {
        x = random(len);
        y = random(len);
        swap(nums[x], nums[y]);
    }
}

int mark = -1; //not good solution

void func1(vector<int> nums)
{
    int outnum = 0;
    while (outnum < nums.size())
    {
        int x = random(nums.size());
        if (nums[x] != mark)
        {
            outnum ++;
            cout << nums[x];
            nums[x] = mark;
        }
    }
}

vector<int>*  func2(vector<int>* nums)
{
    int p = 0;
    while (p < nums->size()-1)
    {
        int x = random(nums->size()-p)+p;
        swap(nums[p], nums[x]);
        p++;
    }
    return nums;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
