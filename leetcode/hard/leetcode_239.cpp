#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int> mark;
        list<int> mark_index;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (mark.size() > 0 && mark_index.back() - mark_index.front()+1 == k) {
                mark.pop_front();
                mark_index.pop_front();
            }

            while(mark.size() > 0 && mark.back() < nums[i]) {
                mark.pop_back();
                mark_index.pop_back();
            }
            mark.push_back(nums[i]);
            mark_index.push_back(i);
            if (i >= k-1)
                res.push_back(mark.front());
        }
        return res;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
