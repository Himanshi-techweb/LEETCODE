class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int mini=INT_MAX;
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
              int sum=nums[i]+nums[0]+nums[j];
              mini=min(mini,sum);
            }
        }
        return mini;
    }
};