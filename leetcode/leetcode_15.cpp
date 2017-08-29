#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    //n*n*log(n)
    vector<vector<int>> Sum2(vector<int> nums, int begin, int sum)
    {
        int res_index;
        vector<vector<int>> res;
        if (nums.size()-1 < begin)
            return res;
        int pre;
        for (int i = begin; i <nums.size()-1; i++)
        {
            if (nums[i] != pre || i == begin)
            {
                res_index = BinarySearch(nums, i+1, nums.size(), sum-nums[i]);
                if (res_index == -1)
                    continue;
                else
                {
                    vector<int> one_res;
                    one_res.push_back(-sum);
                    one_res.push_back(nums[i]);
                    one_res.push_back(nums[res_index]);
                    res.push_back(one_res);
                }
                pre = nums[i];
            }
        }
        return res;
    }
    int BinarySearch(vector<int> temp, int low, int high,int target)
    {
        int startv = low, endv = high;
        int mid=-1;
        while (low < high)
        {
            mid = (low+high)/2;
            if (target == temp[mid])
            {
                return mid;
            }
            else if (target > temp[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        low = low - 1;
        if (low >= startv && low < endv && temp[low] == target)
            return low;
        else
            return -1;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>  res;
        if (nums.size() < 3)
            return res;
        sort(nums.begin(), nums.end());
        int pre;
        for (int i = 0; i < nums.size()-2; i++)
        {
            if (nums[i] != pre || i == 0)
            {
                vector<vector<int>> one_reses;
                one_reses = Sum2(nums, i+1, 0-nums[i]);
                for (int j = 0; j < one_reses.size(); j++)
                {
                    res.push_back(one_reses[j]);
                }
                pre = nums[i];
            }
        }
        return res;
    }
    //n*n
    vector<vector<int>> threeSum_v2(vector<int>& nums) {
        vector<vector<int>>  res;
        if (nums.size() < 3)
            return res;
        sort(nums.begin(), nums.end());
        int pre;
        for (int i = 0; i < nums.size()-2; i++)
        {
            if (nums[i] != pre || i == 0)
            {
            int startv = i+1, endv = nums.size()-1;
            while (startv < endv)
            {
                if (nums[startv] + nums[endv] == 0 - nums[i])
                {
                    vector<int> one_res;
                    one_res.push_back(nums[i]);
                    one_res.push_back(nums[startv]);
                    one_res.push_back(nums[endv]);
                    res.push_back(one_res);
                    while (startv < endv && nums[startv] == nums[startv+1]) startv++;
                    while (startv < endv && nums[endv] == nums[endv-1]) endv--;
                    startv++;
                    endv--;
                }else if (nums[startv] + nums[endv] > 0 - nums[i])
                    endv--;
                else
                    startv++;
            }
            pre = nums[i];
            }
        }
        return res;
    }
};
