#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

class Solution {
public:
    vector<int> ori_permutation;
    Solution(vector<int> nums) {
        ori_permutation.clear();
        for (int i = 0; i < nums.size(); i++) {
            ori_permutation.push_back(nums[i]);
        }
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return ori_permutation;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> rand_permutation = ori_permutation;
        int n = ori_permutation.size();
        for (int i = 0; i < n; i++) {
            //srand(time(NULL)); if not, will not pass
            swap(rand_permutation[i], rand_permutation[rand()%(n-i)+i]);

        }
        return rand_permutation;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    Solution* obj = new Solution(nums);
    vector<int> param_1 = obj->reset();
    vector<int> param_2 = obj->shuffle();
    cout << "Hello world!" << endl;
    return 0;
}
