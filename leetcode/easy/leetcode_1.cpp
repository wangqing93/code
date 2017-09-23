#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>

using namespace std;

class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<pair<int, int>> temp;
        vector<int> ans;
        int res;
        for (int i = 0;i <nums.size(); i++)
        {
            temp.push_back(make_pair(i, nums[i]));
        }
        sort(temp.begin(), temp.end(),[](pair<int, int>& a, pair<int, int>& b){ return a.second < b.second;});
        for (int i = 0; i < temp.size(); i++)
        {
            if (target-temp[i].second > temp[i].second)
                res = findIndex(temp, i+1, temp.size(), target-temp[i].second );
            else
                res = findIndex(temp, 0, i, target-temp[i].second );
            //cout << target-temp[i].second << " " << res << endl;
            if ( res != -1)
            {
                ans.push_back(temp[i].first);
                ans.push_back(temp[res].first);
                //cout << temp[i].first << " " << temp[res].first << endl;
                return ans;
            }
        }
        return vector<int>();
    }

    vector<int> twoSum_v2(vector<int>& nums, int target)
    {
        unordered_map<int,int>  markKey;
        vector<int> ans;
        int find_value;
        for (int i = 0; i < nums.size(); i++)
        {
            find_value = target - nums[i];
            if (markKey.find(find_value)!= markKey.end())
            {
                ans.push_back(markKey.find(find_value)->second);
                ans.push_back(i);
                return ans;
            }
            markKey.insert(make_pair(nums[i], i));
        }
    }
    int findIndex(vector<pair<int, int>> temp, int low, int high,int target)
    {
        int mid=-1;
        while (low < high)
        {
            mid = (low+high)/2;
            if (target == temp[mid].second)
            {
                return mid;
            }
            else if (target > temp[mid].second)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        if (temp[--low].second == target)
            return low;
        else
            return -1;
    }
};

