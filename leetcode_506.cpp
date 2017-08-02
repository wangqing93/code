#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pair<int, int>> temp, temp1;
        vector<string> res;
        string temp2;
        for (int i = 0 ; i < nums.size(); i++)
            temp.push_back(make_pair(nums[i],i));
        sort(temp.begin(), temp.end(), [](pair<int, int>& a, pair<int, int>& b){ return a.first > b.first;});
        for (int i = 0; i < nums.size(); i++)
            temp1.push_back(make_pair(temp[i].second, i));
        sort(temp1.begin(), temp1.end(), [](pair<int, int>& a, pair<int, int>& b){ return a.first < b.first;});
        for (int i = 0 ;i < nums.size(); i++)
        {
            if (temp1[i].second == 0)
                temp2 = "Gold Medal";
            else if (temp1[i].second == 1)
                temp2 = "Silver Medal";
            else if (temp1[i].second == 2)
                temp2 = "Bronze Medal";
            else
                temp2 = to_string(temp1[i].second+1);
            res.push_back(temp2);
        }

        return res;

    }
};
