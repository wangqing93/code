struct pair_hash
{
    template<class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const
    {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int, int> temp;
        sort(nums.begin(), nums.end());
        vector<int> oneres;
        unordered_map<pair<int, int>, int, pair_hash> Map;
        for (int i = 0 ; i < nums.size(); i++) {
            if (temp.count(nums[i]))
                temp[nums[i]]++;
            else
                temp[nums[i]]=1;
        }
        bool threeSame = false;
        for (int i = 0 ; i < nums.size(); i++) {
            
            if (threeSame == true) {
                if (i < nums.size()-1 && nums[i] == nums[i+1])
                    continue;
                else {
                    threeSame = false;
                }
            }
            temp[nums[i]]--;
            for (int j = i; j < nums.size(); j++) {
                if (temp[nums[j]] == 0)
                    continue;
                temp[nums[j]]--;
                if (temp.count(0-nums[i]-nums[j]) && temp[0-nums[i]-nums[j]]>0) {
                    oneres.clear();
                    oneres.push_back(nums[i]);
                    oneres.push_back(nums[j]);
                    oneres.push_back(0-nums[i]-nums[j]);
                    sort(oneres.begin(), oneres.end());
                    if (!Map.count(make_pair(oneres[0], oneres[1]))) {
                        Map[make_pair(oneres[0], oneres[1])] = oneres[2];
                        res.push_back(oneres);
                        if (oneres[0] == oneres[1] && oneres[1] == oneres[2])
                            threeSame = true;
                    }
                    
                }
                temp[nums[j]]++;
            }
            temp[nums[i]]++;
        }

        

        return res;
    }


};
