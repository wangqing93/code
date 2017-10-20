#include <iostream>
#include <vector>
#include <queue>


using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //max 存前k小元素，堆顶就是第k大喽
        priority_queue<int> mark;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (mark.size() < k) {
                    mark.push(matrix[i][j]);
                } else {
                    if (matrix[i][j] < mark.top()) {
                        mark.pop();
                        mark.push(matrix[i][j]);
                    } else {
                        break;
                    }
                }
            }
        }
        return mark.top();
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
