class Solution {
public:
    vector<string> res;
    int length;
     //这个题目非常有趣，昨晚又晚睡了，导致今日状态有点不佳，做了一个很长的梦，梦里让我学英语hh
    //方案1: 暴力法，用回溯生成所有的可能结果，然后用栈验证它（2^(2n)*n）
    //方案2: 回溯方法也不错，每次如果左括号没有添加到最大值，那就添加一个左括号；如果右括号的数目小于左括号，可以添加一个右括号，最终回溯出来的都是结果
    //方案3: 动态规划，比如求n=3的括号组合，我们可以参考n=2的括号组合()() (())  【与方案2类似，动态规划比较容易理解】
    //--参考链接：https://leetcode-cn.com/problems/generate-parentheses/solution/zui-jian-dan-yi-dong-de-dong-tai-gui-hua-bu-lun-da/
    //--剩下的括号要么在这一组新增的括号（）内部，要么在这一组新增括号的外部（右侧）。
    //既然知道了 i<n 的情况，那我们就可以对所有情况进行遍历：
    //"(" + 【i=p时所有括号的排列组合】 + ")" + 【i=q时所有括号的排列组合】
    //其中 p + q = n-1，且 p q 均为非负整数。
    //事实上，当上述 p 从 0 取到 n-1，q 从 n-1 取到 0 后，所有情况就遍历完了。
    //注：上述遍历是没有重复情况出现的，即当 (p1,q1)≠(p2,q2) 时，按上述方式取的括号组合一定不同。
    //方案4:简化版的方案3，递归组合直接得到答案，类似这个题解里面说的闭合数https://leetcode-cn.com/problems/generate-parentheses/solution/gua-hao-sheng-cheng-by-leetcode/

    //方案1
    /*vector<string> generateParenthesis(int n) {
        length = n * 2;
        dfs("", 0);
        return res;
    }

    void dfs(string str, int depth){
        if (depth == length) {
            if (checkStr(str))
                res.push_back(str);
            return;
        }
        dfs(str+"(", depth+1);
        dfs(str+")", depth+1);
    }

    bool checkStr(string str) {
        stack<char> temp;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(')
                temp.push('(');
            else {
                if (temp.empty())
                    return false;
                else
                    temp.pop();
            }
        }
        if (temp.empty())
            return true;
        else
            return false;
    }*/

    //方案4
    /*vector<string> generateParenthesis(int n) {
        vector<string> middleRes;
        if (n == 0)
            middleRes.push_back("");
        for (int i = 0; i < n; i++) {
            int p = i;
            int q = n-1-i;
            vector<string> pRes = generateParenthesis(p);
            vector<string> qRes = generateParenthesis(q);
            string str;
            for (int j = 0; j < pRes.size(); j++) {
                for (int k = 0; k < qRes.size(); k++) {
                    str = '(' + pRes[j]+')'+qRes[k];
                    middleRes.push_back(str);
                }
            }
        }
        return middleRes;
    }*/

    //方案2
    vector<string> generateParenthesis(int n) {
        //回溯，记录左括号的个数x， 记录有括号的个数y
        backtracking(0,0,n,"");
        return res;
    };

    void backtracking(int ln, int rn, int n, string s) {
        if (ln == n && rn== n) {
            res.push_back(s);
            return;
        }
        string oriS = s;
        if (ln > rn) {
            s += ")";
            backtracking(ln, rn+1, n, s);
        }
        s = oriS;
        if (ln < n) {
            s += "(";
            backtracking(ln+1, rn, n, s);
        }
    }


};
