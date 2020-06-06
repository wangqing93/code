class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> existed;
        for (int i = 0; i < nums.size(); i++) {
            if (existed.find(nums[i]) == existed.end())
                existed.insert(make_pair(nums[i], -1));
        }
        int maxLength = 0;
        for (int i = 0; i < nums.size(); i++) {
            int start = nums[i];
            int length = 0;
            while (true) {
                if (existed.find(start) == existed.end()) {
                    for (int j = nums[i]; j < start; j++) {
                        existed[j] = length - (j-nums[i]);
                        //cout << j << ": " << existed[j] << endl;
                    } 
                    maxLength = max(maxLength, length);
                    break;
                } else {
                    if (existed[start] == -1) {
                        start++;
                        length++;
                    } else {
                        for (int j = nums[i]; j < start; j++) {
                            existed[j] = length - (j-nums[i]) + existed[start];
                            //cout << j << ": " << existed[j] << endl;
                        } 
                        maxLength = max(maxLength, existed[nums[i]]);
                        break;
                    }
                }
            }
        } 
        return maxLength; 
    }
};
