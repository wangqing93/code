#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        //�����и�����0����������3������ÿ����3�ֿ��ܣ���27�ֿ��ܣ���ʵ���ϲ�������0����Ϊ������С�ģ���ôÿ����2�ֿ��ܣ�8��
        if (nums[nums.size()-1] <= 0)
        {
            return nums[nums.size()-1] *nums[nums.size()-2] *nums[nums.size()-3];
        } else
        {

            return max(nums[nums.size()-1] *nums[nums.size()-2] *nums[nums.size()-3], nums[0]*nums[1]*nums[nums.size()-1]);
        }

    }
};
