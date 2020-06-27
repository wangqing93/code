class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //把每个元素放到自己的位置上，比如1放在index=0的位置，已经处理过的元素值改为-1
        if (nums.size() == 0)
            return 1;
        if (nums.size() == 1)
            return nums[0]==1?2:1;
        while(true) {
            int startIndex = -1;
            int curV;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] < 1 || nums[i] > nums.size())
                    continue;
                if (nums[i] != i+1) {
                    startIndex = i;
                    curV = nums[i];
                    break;
                }
            }
            if (startIndex == -1)
                break;
            //cout << startIndex <<  " " << curV << endl;
            nums[startIndex] = -1;
            while (true) {
                if (curV < 1 || curV > nums.size())
                    break;
                int temp = nums[curV-1];
                if (curV == temp)
                    break;
                nums[curV-1] = curV;
                curV = temp;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i+1)
                return i+1;
        }
        return nums.size()+1;
    }
};
