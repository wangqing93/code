class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> min_price;
        for (int i = 0; i < prices.size(); i++) {
            if (i == 0) {
                min_price.push_back(prices[i]);
            } else {
                if (min_price[min_price.size()-1] >= prices[i]) {
                    min_price.push_back(prices[i]);
                } else {
                    min_price.push_back(min_price[min_price.size()-1]);
                }
            }
        }
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] - min_price[i-1] > res)
                res = prices[i] - min_price[i-1];
        }
        return res;
    }
};
