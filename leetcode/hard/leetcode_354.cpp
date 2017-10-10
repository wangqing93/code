#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        for (int i = 0; i < envelopes.size(); i++) {
            cout << envelopes[i].first << " " << envelopes[i].second << endl;
        }
        vector<int> dp;
        for (int i = 0; i < envelopes.size(); i++)
            dp.push_back(1);
        int res = 0;
        for (int i = 0; i < envelopes.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second)
                    dp[i] = max(dp[i], dp[j]+1);
            }
            res = max(dp[i], res); 
        }
        return res;
    }
};

int main()
{
    vector<pair<int, int>> envelopes;
    envelopes.push_back(make_pair(5,4));
    envelopes.push_back(make_pair(6,4));
    envelopes.push_back(make_pair(6,7));
    envelopes.push_back(make_pair(2,3));
    Solution t;
    cout << t.maxEnvelopes(envelopes);
    cout << "Hello world!" << endl;
    return 0;
}
