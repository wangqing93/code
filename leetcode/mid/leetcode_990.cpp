class UnionFind {
private:
    int father[100];// 父节点
    int maxIndex;
public:
    UnionFind(int maxIndex) {
        this->maxIndex = maxIndex;
        for(int i = 0; i <= maxIndex; i++) {
            father[i] = -1;
        }
    }
 
    ~UnionFind() {
    }
    int findRoot(int x) {
        // 如果我自己就是-1，那么我就是根
        // 如果我不是-1，找我father的根
        int current = x;
        while(father[current] != -1) {
            current = father[current];
        }
        return current;
    }
 
    bool isConnected(int x, int y) {
        return findRoot(x) == findRoot(y);
    }
 
    bool connect(int x, int y) {
        int xRoot = findRoot(x);
        int yRoot = findRoot(y);
        if (xRoot == yRoot) {
            return false;
        } else {
            father[yRoot] = xRoot;
            return true;
        }
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        //将所有等于的节点构成一个并查集合，然后检测所有不等于的如果在一个并查集合，那就返回true
        //有可能是多个并查集合
        UnionFind t(26); 
        for (int i = 0; i < equations.size(); i++) {
            if (equations[i][1] == '!' ) {
                continue;
            }
            int x = int(equations[i][0] - 'a');
            int y = int(equations[i][3] - 'a');
            t.connect(x, y);
        }
        for (int i = 0; i < equations.size(); i++) {
            if (equations[i][1] == '!' ) {
                int x = int(equations[i][0] - 'a');
                int y = int(equations[i][3] - 'a');
                if (t.isConnected(x, y))
                    return false;
            }    
        }
        return true;
    }
};
