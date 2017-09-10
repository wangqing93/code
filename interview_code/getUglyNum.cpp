#include <iostream>
#include <vector>

using namespace std;

int minTree(int x, int y, int z)
{
    int max2 = (x>y)?y:x;
    return (max2>z)?z:max2;
}
int getUglyNum(int index)
{
    if (index == 1)
        return 1;
    vector<int> uglynums;
    uglynums.push_back(1);
    int max2,max5,max3,maxV;
    bool flag2,flag5,flag3;
    while(uglynums.size() < index)
    {
        maxV = uglynums[uglynums.size()-1];
        flag2 = false;
        flag3 = false;
        flag5 = false;

        for (int i = 0; i < uglynums.size(); i++)
        {
            if (flag2 && flag3 && flag5)
            {
                break;
            }
            if (flag2 == false && uglynums[i]*2 > maxV)
            {
                max2 = uglynums[i]*2;
                flag2 = true;
            }
            if (flag3 == false && uglynums[i]*3 > maxV)
            {
                max3 = uglynums[i]*3;
                flag3 = true;
            }
            if (flag5 == false && uglynums[i]*5 > maxV)
            {
                max5 = uglynums[i]*5;
                flag5 = true;
            }
        }
        uglynums.push_back(minTree(max2,max3,max5));
    }
    return uglynums[uglynums.size()-1];
}

int main()
{
    int num;
    cin >> num;
    cout << getUglyNum(num);
    return 0;
}
