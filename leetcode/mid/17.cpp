#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int digits_len =digits.length();
        string repre[10] = {"", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res;
        for (int i = 0; i < digits_len; i++) {
            if (digits[i] < '0' || digits[i] > '9')
                return vector<string>();
            int key = digits[i] - '0';
            //cout << key << endl;
            if (i == 0) {
                //cout << repre[key].length() << endl;
                for (int k = 0; k < repre[key].length(); k++) {
                        res.push_back(repre[key].substr(k,1));
                }
            } else {
                int m = res.size();
                //cout << m << endl;
                for (int j = 0; j < m; j++) {
                    for (int k = 0; k < repre[key].length()-1; k++) {
                        res.push_back(res[j]+repre[key].substr(k,1));
                    }
                }
                for(int j = 0; j < m; j++) {
                    res[j] = res[j]+repre[key].substr(repre[key].length()-1, 1);
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution t;
    vector<string>  res = t.letterCombinations("23");
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
    cout << "Hello world!" << endl;
    return 0;
}
