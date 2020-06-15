class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        int resIndex = backtracking(strs, 0);
        //cout << resIndex << endl;
        if (resIndex < 0)
            return "";
        else
            return strs[0].substr(0, resIndex+1);
    }

    int backtracking(vector<string> strs, int index) {
        //out << "start find: " << index << endl;
        if (index == strs[0].length())
            return index-1;
        char target = strs[0][index];
        for (int i = 0; i < strs.size(); i++) {
            if (target != strs[i][index]) {
                //cout << "target not equal" << index-1 << endl; 
                return index-1;
            }
                
        }
        return backtracking(strs, index+1);
    }

};
