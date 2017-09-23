#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> res;
        int mark = sqrt(area);
        while (area % mark != 0)
            mark--;
        res.push_back(area/mark);
        res.push_back(mark);
        return res;
    }
};
