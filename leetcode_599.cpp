#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        vector<string> temp;
        unordered_map<string, int> str;
        int mark_min = -1;
        if (list1.size() > list2.size())
        {
            temp = list1;
            list1 = list2;
            list2 = temp;
        }
        for (int i = 0; i < list2.size(); i++)
            str.insert(make_pair(list2[i], i));
        for (int i = 0; i < list1.size(); i++)
        {
            unordered_map<string, int>::const_iterator find_str = str.find(list1[i]);
            if (find_str!= str.end())
            {
                if (mark_min > i + find_str->second || mark_min == -1)
                {
                    mark_min = i + find_str->second;
                    res.clear();
                    res.push_back(list1[i]);
                }else if (mark_min == i + find_str->second)
                    res.push_back(list1[i]);
            }
        }
        return res;
    }
};
