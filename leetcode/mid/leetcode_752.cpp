class Solution {
public:
    string plusStr(string str, int i) {
        if(str[i]=='9')
        {
            str[i]='0';
        }
        else{
            str[i]=str[i]+1;
        } 
        return str;
    }
    string minusStr(string str, int i) {
        if(str[i]=='0')
        {
            str[i]='9';
        }
        else{
            str[i]=str[i]-1;
        }
        return  str;
    }
    int openLock(vector<string>& deadends, string target) {
        //最小的旋转次数，所以是bfs
        unordered_map<string, bool> isDead;
        for (int i = 0; i < deadends.size(); i++) {
            if (isDead.find(deadends[i]) == isDead.end())
                isDead.insert(make_pair(deadends[i], true));
        }
        queue<string> oneLevel;
        oneLevel.push("0000");
        unordered_map<string, bool> visited;
        visited.insert(make_pair("0000", true));
        int step = 0;
        while(!oneLevel.empty()) {
            int n = oneLevel.size();
            for (int k = 0; k < n; k++) {
                string node = oneLevel.front();
                oneLevel.pop();
                if (isDead.find(node) != isDead.end())
                    continue;
                if (node == target)
                    return step;
                for (int i = 0; i < 4; i++) {
                    string one = plusStr(node, i);
                    if (visited.find(one) == visited.end()) {
                        oneLevel.push(one);
                        visited.insert(make_pair(one, true)); 
                    }
                    string two = minusStr(node, i);
                    if (visited.find(two) == visited.end()) {
                        oneLevel.push(two);
                        visited.insert(make_pair(two, true));
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
