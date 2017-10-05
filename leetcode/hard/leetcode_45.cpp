#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        int curPos = 0;
        int endPos = nums.size()-1;
        int nextPos, curStep;
        int step = 0;
        while(curPos < endPos)
        {
            if (nums[curPos] >= endPos - curPos)
                return step + 1;
            nextPos = nums[curPos];
            curStep = 0;
            for (int i = 1; i <= nums[curPos]; i++)
            {
                if (i + nums[curPos+i] >= endPos - curPos)
                    return step + 2;
                if (i + nums[curPos+i] > nextPos)
                {
                    nextPos = i + nums[curPos+i];
                    curStep = i;
                }

            }
            curPos += curStep;
            step = step + 1;
            //cout << curPos << " " << step << endl;
        }
        return step;
    }
};

int main()
{
    vector<int> test;
    test.push_back(1);
    test.push_back(1);
    test.push_back(1);
    test.push_back(1);
    /*test.push_back(5);
    test.push_back(4);
    test.push_back(3);*/

    Solution t;
    cout << t.jump(test);
    //cout << "Hello world!" << endl;
    return 0;
}
