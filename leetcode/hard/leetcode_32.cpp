#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> midres;
        int res = 0;
        int flagIndex = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ')')
            {
                if (midres.empty())
                {
                    flagIndex = i+1;
                }
                else
                {
                    midres.pop();
                    if (midres.empty())
                        res = max(res, i-flagIndex+1);
                    else
                        res = max(res,i-midres.top());
                }
            } else
                midres.push(i);

        }
        return res;
    }
};

int main()
{
    Solution test;
    cout << test.longestValidParentheses(")()())") << endl;
    cout << test.longestValidParentheses("(()") << endl;
    cout << test.longestValidParentheses("(())()())") << endl;
    cout << test.longestValidParentheses("()") << endl;
    cout << test.longestValidParentheses("()(()") << endl;
    cout << "Hello world!" << endl;
    return 0;
}
