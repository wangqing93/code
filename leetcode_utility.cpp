#include <iostream>
#include <vector>

using namespace std;

class utility
{
public:
    int BinarySearch(vector<int> temp, int low, int high,int target)
    {
        int mid=-1;
        while (low < high)
        {
            mid = (low+high)/2;
            if (target == temp[mid])
            {
                return mid;
            }
            else if (target > temp[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        if (temp[--low] == target)
            return low;
        else
            return -1;
    }
};

