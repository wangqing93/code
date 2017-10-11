#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        int x = 1;
        vector<int> res;
        res.push_back(0);
        for (int i = 1; i <= num; i++) {
           if (i == x) {
                res.push_back(1);
                for (int j = 1; j <= x-1 && res.size() <= num; j++) {
                    res.push_back(res[j]+1);
               }
               x = x << 1;
               i = x-1;
           }
        }
        return res;
    }
};

int main()
{
    Solution t;
    vector<int> res = t.countBits(5);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}
