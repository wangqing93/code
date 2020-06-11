class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        //方案1：找到序号中第一个比他大的数字
        //先n用map标记温度，温度按照顺序出现的次数
        //对于每一个温度，二分法找该温度依次往后的温度，是否有index比当前大的70nlogn

        //方案2：纯暴力，往后找，找到比当前值大的n*n

        //方案3：单调栈，其实之前做过这题，但是没理解透彻
        //栈的元素单调递减，一旦新的元素大于栈顶元素，则可以pop更新值
        //栈里面的元素需要标记两个值（value, index）
        stack<pair<int, int>> eles;
        unordered_map<int, int> midres;
        vector<int> res;

        for (int i = 0; i < T.size(); i++) {
            int v = T[i];
            while (!eles.empty() && v > eles.top().first) {
                pair<int, int> top_stack = eles.top();
                midres[top_stack.second] = i - top_stack.second;
                eles.pop();
            }
            eles.push(make_pair(v, i));
        }
        for (int i = 0; i < T.size(); i++)
            res.push_back(midres[i]);
        return res;

    }
};
