#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> nums_count;
        unordered_map<int, vector<int>> mark;
        for (int i = 0; i < nums.size(); i++) {
            if (nums_count.find(nums[i]) == nums_count.end())
                nums_count[nums[i]] = 1;
            else
                nums_count[nums[i]]++;
        }
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto i = nums_count.begin(); i != nums_count.end(); i++) {
            if (mark.find(i->second) == mark.end()) {
                vector<int> temp;
                temp.push_back(i->first);
                mark[i->second] = temp;
            } else {
                mark[i->second].push_back(i->first);
            }
            if (q.size() < k) {
                q.push(i->second);
            } else {
                if (i->second > q.top()) {
                    q.pop();
                    q.push(i->second);
                }
            }
        }
        vector<int> res;
        while(!q.empty()) {
            int t1 = q.top();
            vector<int> t = mark[t1];
            for (int j = 0;  j < t.size() && res.size()< k ; j++)
                res.push_back(t[j]);
            while(t1 == q.top()) {
                q.pop();
                if (q.empty())
                    break;
            }
        }
        return res;
    }

};

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    Solution t;
    t.topKFrequent(nums, 2);
    cout << "Hello world!" << endl;
    return 0;
}
