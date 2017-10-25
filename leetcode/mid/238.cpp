#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftres;
        vector<int> rightres;
        leftres.push_back(1);
        rightres.push_back(1);
        for (int i = 1; i < nums.size(); i++) {
            leftres.push_back(leftres[i-1] * nums[i-1]);
            rightres.push_back(rightres[i-1]*nums[nums.size()-i]);
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0)
                res.push_back(rightres[nums.size()-1]);
            else if ( i == nums.size()-1)
                res.push_back(leftres[nums.size()-1]);
            else
                res.push_back(leftres[i]*rightres[nums.size()-i-1]);
        }
        return res;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
