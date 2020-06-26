class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 入度
        // 边
        unordered_map<int, vector<int>> rels;
        int* inDs = new int[numCourses];
        for (int i = 0; i < numCourses; i++) {
            inDs[i] = 0;
            vector<int> temp;
            rels[i] = temp;
        }
            
        for (int i = 0 ; i < prerequisites.size(); i++) {
            rels[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDs[prerequisites[i][0]]++;
        }
        queue<int> zeroInD; // zero indgree
        vector<int> res;
        int num = 0;
        while (num != numCourses) {
            for (int i = 0; i < numCourses; i++) {
                if (inDs[i] == 0) {
                    zeroInD.push(i);
                    num++;
                    inDs[i] = -1;
                }
            }
            if (zeroInD.empty() && num!=numCourses)
                return vector<int>();
            while (!zeroInD.empty()) {
                int topV = zeroInD.front();
                res.push_back(topV);
                zeroInD.pop();
                vector<int> topVEdges = rels[topV];
                for (int j = 0; j < topVEdges.size(); j++) {
                    inDs[topVEdges[j]]--;
                }
            }
        }
        return res;
    }
};
