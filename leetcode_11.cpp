#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = -1, area = -1;
        for (int left = 0; left < height.size(); left++)
        {
            for (int right = height.size() -1; right >left; right--)
            {
                area = (right-left) * min(height[right], height[left]);
                if (max_area < area)
                    max_area = area;
            }
        }
        return max_area;
    }

    int maxArea_v2(vector<int>& height) {
        int max_area = -1, left = 0, right = height.size()-1;
        while (left < right)
        {
            max_area = max(max_area, (right-left) * min(height[right], height[left]));
            if (height[left] < height[right])
            {
                left++;
            }else
            {
                right--;
            }
        }
        return max_area;
    }
};

