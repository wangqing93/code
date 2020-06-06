class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int maxCandies = -1;
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] > maxCandies)
                maxCandies = candies[i];
        }
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i]+extraCandies >= maxCandies) {
                res.push_back(true);
            }
            else {
                res.push_back(false);
            }
        }
        return res;
    }
};
