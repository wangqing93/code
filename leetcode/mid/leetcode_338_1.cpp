class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        int curBinary = 1;
        res.push_back(0);
        for (int i = 1; i <= num; i++) {
            if (i == curBinary) {
                res.push_back(1);
                curBinary*=2;
            }    
            else {
                int temp = i-curBinary/2;
                res.push_back(res[temp]+1);
            }
        }
        return res;
    }
};
