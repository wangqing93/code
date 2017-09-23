#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:

    void print(vector<int> values)
    {
        for (int i = 0; i < values.size(); i++)
            cout << values[i] << " ";
        cout <<endl;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k,0);
        if (k > nums1.size() + nums2.size())
            return res;
        //nums1.size()>=i
        //nums2.size()>=k-i  i >= k-nums2.size()
        int m = nums1.size(), n = nums2.size();
        for (int i = max(0, k-n); i <= min(k, m); i++)
        {
            vector<int> Ares = ChooseNumber(nums1, i);
            print(Ares);
            vector<int> Bres = ChooseNumber(nums2, k-i);
            print(Bres);
            vector<int> mergeres = mergeRes(Ares, Bres);
            print(mergeres);
            if (judgeWhois(mergeres, res, 0,0))
                res = mergeres;
        }
        return res;
    }
    bool judgeWhois(vector<int> nums1, vector<int> nums2, int x1, int x2)
    {

        while (x1 < nums1.size() && x2 < nums2.size() && nums1[x1] == nums2[x2])
        {
            x1++;
            x2++;
        }
        if (x2 == nums2.size())
            return true;
        if (x1 == nums1.size())
            return false;
        return nums1[x1] > nums2[x2];
    }
    vector<int> mergeRes(vector<int> nums1, vector<int> nums2)
    {
        vector<int> res; int index1 = 0, index2 = 0;
        while (index1 < nums1.size() && index2 < nums2.size())
        {
            if (judgeWhois(nums1, nums2, index1, index2))
            {
                res.push_back(nums1[index1]);
                index1++;
            }
            else
            {
                res.push_back(nums2[index2]);
                index2++;
            }
        }
        while (index1 < nums1.size())
            res.push_back(nums1[index1++]);
        while (index2 < nums2.size())
            res.push_back(nums2[index2++]);
        return res;
    }
    vector<int> ChooseNumber(vector<int>& nums, int k)
    {
        vector<int> res;
        int maxTemp = -1, j = 0, maxIndex, nSize = nums.size();
        for (int i = 1; i <= k; i++)
        {
            maxTemp = -1;
            while(j < nSize -(k-i))
            {
                if (nums[j] > maxTemp)
                {
                    maxTemp = nums[j];
                    maxIndex = j;
                }
                j++;
            }
            res.push_back(maxTemp);
            j = maxIndex + 1;
        }
        return res;
    }
};


int main()
{
    vector<int> A;
    vector<int> B;
    vector<int> res;
    A.push_back(3);
    A.push_back(4);
    A.push_back(6);
    A.push_back(1);

    B.push_back(1);
    B.push_back(1);
    B.push_back(1);

    B.push_back(2);
    B.push_back(2);

    int k = 5;

    Solution test;
    res = test.maxNumber(A, B, k);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << "Hello world!" << endl;
    system("pause");
    return 0;
}
