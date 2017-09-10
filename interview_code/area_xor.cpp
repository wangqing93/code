/*
Didi  second question 20170910 area xor
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct node
{
    int lastAreaLeft;
    int lastAreaRight;
    int xorZeroNums;
    int lastAreaxorValue;
    node(int x, int y)
    {
        lastAreaLeft = x;
        lastAreaRight = y;
    }
};
int main()
{
    int nums, temp;
    vector<int> values;
    cin >> nums;
    for (int i =0;i <nums; i++)
    {
        cin >> temp;
        values.push_back(temp);
    }
    sort(values.begin(), values.end());
    vector<node> possibles;
    if (nums == 0)
    {
        cout << 0;
        return 0;
    }
    node temp1(0,0);
    temp1.xorZeroNums = values[0]==0?1:0;
    temp1.lastAreaxorValue=values[0];
    possibles.push_back(temp1);
    if (nums == 1)
    {
         cout << temp1.xorZeroNums;
         return 0;
    }
    int temp2, maxV=0, possiblesSize= 0;
    for (int i = 1; i < values.size(); i++)
    {
        possiblesSize = possibles.size();
        for (int j = 0; j < possiblesSize; j++)
        {
            if (values[i-1] == values[i])
            {
                temp2 = possibles[j].lastAreaxorValue;
                possibles[j].lastAreaxorValue^=values[i];
                possibles[j].lastAreaRight++;
                if (possibles[j].lastAreaxorValue == 0 && temp2 !=0)
                    possibles[j].xorZeroNums++;
                else if (possibles[j].lastAreaxorValue != 0 && temp2 ==0)
                    possibles[j].xorZeroNums--;

                if (i == values.size()-1 && possibles[j].xorZeroNums > maxV)
                    maxV = possibles[j].xorZeroNums;

            } else
            {
                temp1.lastAreaLeft = i;
                temp1.lastAreaRight = i;
                temp1.lastAreaxorValue = values[i];
                temp1.xorZeroNums = values[i]==0?possibles[j].xorZeroNums+1:possibles[j].xorZeroNums;
                possibles.push_back(temp1);

                if (i == values.size()-1 && possibles[j].xorZeroNums > maxV)
                    maxV = possibles[j].xorZeroNums;

                temp2 = possibles[j].lastAreaxorValue;
                possibles[j].lastAreaxorValue^=values[i];
                possibles[j].lastAreaRight++;
                if (possibles[j].lastAreaxorValue == 0 && temp2 !=0)
                    possibles[j].xorZeroNums++;
                else if (possibles[j].lastAreaxorValue != 0 && temp2 ==0)
                    possibles[j].xorZeroNums--;

                if (i == values.size()-1 && possibles[j].xorZeroNums > maxV)
                    maxV = possibles[j].xorZeroNums;
            }
        }
    }
    cout << maxV << endl;
    return 0;
}
