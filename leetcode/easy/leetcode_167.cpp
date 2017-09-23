#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0,r=numbers.size()-1, temp;
        vector<int> res;
        while(true)
        {
            temp = numbers[l]+numbers[r];
            if (temp==target)
            {
                res.push_back(l+1);
                res.push_back(r+1);
                return res;
            }else if (temp > target)
                r--;
            else
                l++;
        }
        return res;
    }
};

//���ֲ��������⣬runtime error ����Խ�硢ջ��������ʷǷ��ڴ�
