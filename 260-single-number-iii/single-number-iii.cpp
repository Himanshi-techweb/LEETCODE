class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> cnt;
        vector<int> ans;
        for(int num:nums){    
                cnt[num]++;  
        }
        for(auto it:cnt)if(it.second==1)ans.push_back(it.first);
        return ans;
    }
};