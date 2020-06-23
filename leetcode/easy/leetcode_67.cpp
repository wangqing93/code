class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() > b.length())
            swap(a,b);
        // b longer
        int add = 0;
        string res ="";
        for (int i = b.length()-1; i >= 0; i--) {
            int charA = 0;
            int charB = int(b[i]-'0');
            int aIndex = i-b.length()+a.length();
            if (aIndex >= 0)
                charA = int(a[aIndex]-'0');
            int cur = (charB+charA+add)%2;
            add = (charB+charA+add)/2;
            if (cur == 0)
                res+='0';
            else
                res+='1';
        }
        if (add == 1)
            res+='1';
        //cout << res << endl;
        for (int i = 0; i < res.length()/2; i++) {
            swap(res[i], res[res.length()-i-1]);
        }
        return res;
    }
};
