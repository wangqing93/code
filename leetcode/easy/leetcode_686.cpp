#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int m = A.length(), x = B.length();
        int n = x/m;
        string str = A;
        for (int i = 1; i < n+2; i++)
        {
            A+=str;
        }
        for (int i = 0; i < A.length()-x; i++) {
            if (A.substr(i, x) == B)
                return (i+x-1)/m+1;
        }
        return -1;
    }
};

int main()
{
    Solution t;
    cout << t.repeatedStringMatch("bcacbcbbbbbbbacbcaacbccaa", "bbcacbcbbbbbbbacbcaacbccaacbcacbcbbbbbbbacbcaacbccaaabcacbcbbbbbbbacbcaacbccaacbcacbcbbbbbbbacbcaacbccaabbcacbcbbbbbbbacbcaacbccaacbcacbcbbbbbbbacbcaacbccaabbcacbcbbbbbbbacbcaacbccaabbcacbcbbbbbbbacbcaacbccaabbcacbcbbbbbbbacbcaacbccaabbcacbcbbbbbbbacbcaacbccaabbcacbcbbbbbbbacbcaacbccaabbcacbcbbbbbbbacbcaacbccaabbcacbcbbbbbbbacbcaacbccaaabcacbcbbbbbbbacbcaacbccaacbcacbcbbbbbbbacbcaacbccaabbcacbcbbbbbbbacbcaacbccaacbcacbcbbbbbbbacbcaacbccaaabcacbcbbbbbbbacbcaacbccaaabcacbcbbbbbbbacbcaacbccaacbcacbcbbbbbbbacbcaacbccaabbcacbcbbbbbbbacbcaacbccaacbcacbcbbbbbbbacbcaacbccaacbcacbcbbbbbbbacbcaacbccaaabcacbcbbbbbbbacbcaacbccaaa") <<endl;
    cout << t.repeatedStringMatch("abcd", "cdabcdab") << endl;

    return 0;
}
