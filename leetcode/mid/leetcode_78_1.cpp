class Solution {
public:
    //回溯算法我感觉可行,但不知如何下手
    //一个方案是nums的子集长度有n， n-1，----0
    //遍历子集长度的所有可能，那问题来了，比如nums有100个数字，要从中选择55个，你怎么遍历
    //方案1:相关标签，看到了位运算，还在想怎么结合，因为每一个值可以选或者不能选
    //比如这个例子nums的size = 3，那实际上有8中解法
    /*vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int subsetNum = 1 << nums.size();
        for(unsigned int i = 0; i < subsetNum; i++) {  //循环8的
            vector<int> oneres;
            for (int j = 0; j < nums.size(); j++) {
                if (((i>>j)&1) == 1) {
                    oneres.push_back(nums[j]);
                }
                    
            }
            res.push_back(oneres);
        }
        return res;
    }*/
    //方案2: 递归做法, 递归的基本思路，从i个元素到i+1个元素的过程
    //
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0)
            return res;
        backTracking(nums, 0, res);
        res.push_back(vector<int>());
        return res;
    }

    void backTracking(vector<int> nums, int add_index, vector<vector<int>>& subsets) {
        if (add_index == nums.size())
            return;
        vector<vector<int>> newSubsets;
        vector<int> oneSubset;
        for (int i = 0; i < subsets.size(); i++) {
            oneSubset.clear();
            oneSubset = subsets[i];
            oneSubset.push_back(nums[add_index]);
            newSubsets.push_back(oneSubset);
        }
        oneSubset.clear();
        oneSubset.push_back(nums[add_index]);
        newSubsets.push_back(oneSubset);
        for (int i = 0; i < newSubsets.size(); i++) {
            subsets.push_back(newSubsets[i]);
        }
        backTracking(nums, add_index+1, subsets);
    }
};
