#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int n = nums.size();
        int pre_min = nums[0];
        int pre_max = nums[0];
        int cur_min;
        int cur_max;
        int all_max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            cur_min = min(min(pre_max*nums[i], pre_min*nums[i]), nums[i]);
            cur_max = max(max(pre_max*nums[i], pre_min*nums[i]), nums[i]);
            pre_min = cur_min;
            pre_max = cur_max;
            all_max = max(all_max, cur_max);
        }
        return all_max;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
