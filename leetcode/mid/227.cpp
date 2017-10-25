#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int getRes(int a, int b, char c) {
        if (c == '+')
            return a+b;
        else if (c == '-')
            return a-b;
        else if (c == '*')
            return a*b;
        else
            return a/b;
    }
    int calculate(string s) {
        stack<int> midres;
        stack<char> opt;
        bool flagMul = false;
        bool flagDiv = false;
        //if * or / cal res into stack
        //when end， then start cal
        string str = "";
        int a, b;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == ' ') {
                if (s[i] == '+' || s[i] == '-' )
                    opt.push(s[i]);
                if (str != "") {
                    b = atoi(str.c_str());
                    if (flagMul == true || flagDiv == true) {
                        a = midres.top();
                        midres.pop();
                        midres.push(getRes(a, b, flagMul==true?'*':'/'));
                        if (flagMul == true)
                            flagMul = false;
                        else
                            flagDiv = false;
                    } else {
                       midres.push(b);
                    }
                    str = "";
                }
                if (s[i] == '*' || s[i] == '/'){
                     flagMul = (s[i]=='*')?true:false;
                     flagDiv = !flagMul;
                }
            } else {
                str += s[i];
            }
        }

        if (str != "") {
            b = atoi(str.c_str());
            if (flagMul == true || flagDiv == true) {
                a = midres.top();
                midres.pop();
                midres.push(getRes(a, b, flagMul==true?'*':'/'));
                if (flagMul == true)
                    flagMul = false;
                else
                    flagDiv = false;
            } else {
                midres.push(b);
            }
            str = "";
        }
        stack<int> midres1;
        stack<char> opt1;
        while(!opt.empty()) {
            opt1.push(opt.top());
            opt.pop();
        }
        while(!midres.empty()) {
            midres1.push(midres.top());
            midres.pop();
        }
        while(!opt1.empty()) {
            b = midres1.top();
            midres1.pop();
            a = midres1.top();
            midres1.pop();
            midres1.push(getRes(b,a,opt1.top()));
            opt1.pop();
        }
        return midres1.top();
        //return midres.top();
    }
};


int main()
{
    Solution t;
    cout << t.calculate("1*2-3/4+5*6-7*8+9/10");
    cout << "Hello world!" << endl;
    return 0;
}
