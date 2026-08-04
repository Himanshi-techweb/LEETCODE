class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int mini=nums[0];
        int maxi=nums[nums.size()-1];
        vector<int> ans;
        int it=0;
        for(int i=mini;i<maxi;i++){
            //if i is nums[it] then increase it otherwise insert i in ans
            if(i==nums[it])it++;
            else{
                ans.push_back(i);
            }
        }
        return ans;

    }
};