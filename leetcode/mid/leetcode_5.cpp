#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        s = extendString(s);
        //cout << s << endl;
        vector<int> rad;
        for (int i = 0; i < s.length(); i++)
            rad.push_back(0);
        for (int i = 0, j, k; i < s.length(); i+=k)
        {
            j = 1;
            while((i-j)>=0 && (i+j)<s.length() && s[i-j]==s[i+j])
                j++;
            rad[i] = --j; //i
            for (k = 1; k < rad[i] && rad[i]-k != rad[i-k]; k++)
                rad[i+k] = min(rad[i]-k, rad[i-k]);
        }
        int maxLen = -1, midIndex = -1;
        for (int i = 0; i < s.length(); i++)
        {
            //cout << rad[i] << endl;
            if (s[i-rad[i]] == '#')
                rad[i]--;
            if (rad[i] > maxLen)
            {
                maxLen = rad[i];
                midIndex = i;
            }
        }
        string res="";
        for (int i = midIndex - maxLen; i <= midIndex + maxLen; i++)
        {
            if (s[i] != '#')
                res += s[i];
        }
        return res;
    }
    string extendString(string s)
    {
        string res;
        for (int i = 0; i < s.length()-1; i++)
        {
            res += s[i];
            res += '#';
        }
        res += s[s.length()-1];
        return res;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution test;
    cout << test.longestPalindrome(s);
    //cout << "Hello world!" << endl;
    return 0;
}
