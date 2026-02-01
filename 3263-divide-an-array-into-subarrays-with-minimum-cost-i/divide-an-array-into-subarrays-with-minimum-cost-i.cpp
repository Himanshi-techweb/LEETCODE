class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int mini=INT_MAX;
        int mini1=nums[1];int mini2=INT_MAX;
        for(int i=2;i<nums.size();i++){
            if(nums[i]<mini1){
                mini2=mini1;
                mini1=nums[i];
            }
            else if(nums[i]<mini2 ){
                mini2=nums[i];
            }
        }
        return mini1+mini2+nums[0];
    }
};