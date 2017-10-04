#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        s = extendString(s);
        vector<int> rad = calRad(s);
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
    vector<int> calRad(string s)
    {
        vector<int> rad;
        for (int i = 0; i < s.length(); i++)
            rad.push_back(0);
        for (int i = 0, j = 1, k; i < s.length(); i+=k)
        {
            while((i-j)>=0 && (i+j)<s.length() && s[i-j]==s[i+j])
                j++;
            rad[i] = j-1; //i
            for (k = 1; k <= rad[i] && rad[i]-k != rad[i-k]; k++)
                rad[i+k] = min(rad[i]-k, rad[i-k]);
            j = max(j-k, 0);
        }
        return rad;
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
    int countSubstrings(string s)
    {
        int res = 0;
        s = extendString(s);
        vector<int> rad = calRad(s);
        cout << s << endl;
        for (int i = 0; i < s.length(); i++)
        {
            cout << i << " " << rad[i] << endl;
            res += rad[i]/2;
            if (s[i] != '#')
                res++;
            if (s[i-rad[i]] != '#' && rad[i]%2==1)
                res++;
        }
        return res;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution test;
    cout << test.countSubstrings(s) << endl;
    //cout << "Hello world!" << endl;
    return 0;
}
