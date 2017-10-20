#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> res;
        int a, b, c;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                a = res.top();
                res.pop();
                b = res.top();
                res.pop();
                if (tokens[i] == "+") {
                    c = a + b;
                } else if (tokens[i] == "-") {
                    c = b - a;
                } else if (tokens[i] == "*") {
                    c = b * a ;
                } else if (tokens[i] == "/") {
                    c = b / a;
                }
                res.push(c);
            }else {
                if (tokens[i][0] == '-') {
                    res.push(0-atoi(tokens[i].substr(1).c_str()));
                } else {
                    res.push(atoi(tokens[i].c_str()));
                }
                //cout <<res.top() << endl;

            }
        }
        return res.top();
    }
};

int main()
{
    vector<string> t;
    t.push_back("3");
    t.push_back("-4");
    t.push_back("+");
    Solution test;
    cout << test.evalRPN(t);
    cout << "Hello world!" << endl;
    return 0;
}
