class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //有两数之和的，用的暴力法遍历x，再二分查找sum-x，最终复杂度有nlogn，也可以用hashmap去找队友
        //方案1:三数之和，暴力法n*n*logn-n^3，借用hashmap找队友，复杂度会降低到n*n
        //不重复的三元组，那就暴力的过程中，现将数组排序，找出的res均按照从小到大输出
        //方案2:排序，以下四行思路不正确
        //然后整一个left_index，整一个right_index，然后求0-left-right= middle
        //middle有三种可能， middle_index<= left_index, 太小了，要让middle变大，所以你的right--
        //middle_index > left_index && middle_index < right_index: 
        //-可喜可贺有可能有解，有可能无解。left++, right--【你究竟应该移动那一边呢，你移动那一边都会漏掉题解？？】
        //middle_index >= right_index, left--;  值太大了，所以你要把left和index的和变大，所以left++
        vector<vector<int>> res;
        if (nums.size() < 3)
            return res;
        sort(nums.begin(), nums.end());
        
        
        for(int i = 0; i < nums.size()-2; i++) {
            int left = i+1;
            int right = nums.size()-1;
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i-1])
                continue; //会重复，因为nums[i-1]已经找过一边了
            //cout << i << " " << nums[i] << endl;
            while(left < right) { //判断条件，区间内至少2个数hh,一个left，一个right
                //cout << left << " " << right << endl;
                int sum = nums[left] +nums[right] + nums[i];
                //cout << sum << endl;
                if (sum == 0) {
                    vector<int> oneres;
                    oneres.push_back(nums[i]);
                    oneres.push_back(nums[left]);
                    oneres.push_back(nums[right]);
                    res.push_back(oneres);
                    //left一直一样怎么办，right一直一样怎么办
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                } else if (sum > 0){
                    right--;
                } else {
                    left++;
                }
            }
        }
        /* 
        //一段弯路，可借鉴，做题目之前思路要严谨，不然写出来的代码bug太多鸟
        while(left < right-1 ) { //判断条件，区间内至少三个数hh
            int x = nums[left];
            int y = nums[right];
            int z = 0- x - y;
            cout << "index:" << left << " " << right  << " " << endl;
            cout <<"value:" <<  x << " " << y << " " << z << endl;
            int middle = -1;
            for (int i = left+1; i < right; i++) {
                cout << "cycle:" << i << " " << nums[i]  << " "  << z << endl; 
                if (nums[i] == z) {
                    middle = i;
                    vector<int> oneres;
                    oneres.push_back(nums[left]);
                    oneres.push_back(nums[i]);
                    oneres.push_back(nums[right]);
                    res.push_back(oneres);
                    left++;
                    //right--;
                    break;
                }
            }
            if (middle == -1) {
                //没找到答案证明有三种情况
                // left+1, right-1
                if (z <= nums[left+1]) {
                    right--;
                } else if (z >= nums[left+1] && z <= nums[right-1]) {
                    left++;
                    //right--;
                } else {
                    left++;   //你需要一个很大的数，但是你没有那个很大的数，所以你要增加left
                }
            }
        }*/

        return res;
    }


};
