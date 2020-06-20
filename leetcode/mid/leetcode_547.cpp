//并查集 int p[i] = j 表示i的爸爸是j，根节点等于1
//两个节点是不是在一个集合，看他们的根是不是一样



class Solution {
public:
    int *p;
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        if (n == 0)
            return 0;
        p = new int[n];
        for (int i = 0; i < n; i++) {
            newSet(i);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (M[i][j] == 1) {
                    unionSet(i,j);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (p[i] == -1 || p[i] == i)
                res++;

        }
        return res;
        
    }

    int newSet(int x) {
        p[x] = x;
        return x;
    }

    int find(int x) {
        int t = x;
        while(p[t]!= -1 && p[t]!=t){
            t = p[t];
        }
        return t;
    }

    int unionSet(int x, int y) {
        //index da的都做爸爸吧 y是爸爸
        if (y < x)
            swap(x, y);
        int t1 = find(x);
        int t2 = find(y);
        if (t1 != t2) {
            p[t1] = t2;
            p[t2] = -1;
        }
        return t2;
    }




};
