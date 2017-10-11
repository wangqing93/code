#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;


//Definition for undirected graph.
struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mark;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
         if (node == NULL)
            return NULL;
        if (mark.find(node) != mark.end()) {
            return mark[node];
        } else {
            UndirectedGraphNode* t = new UndirectedGraphNode(node->label);
            mark[node] = t;
            for (int i = 0; i < node->neighbors.size(); i++) {
                UndirectedGraphNode* neig = cloneGraph(node->neighbors[i]);
                if (neig != NULL)
                    t->neighbors.push_back(neig);
            }
            return t;
        }
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
