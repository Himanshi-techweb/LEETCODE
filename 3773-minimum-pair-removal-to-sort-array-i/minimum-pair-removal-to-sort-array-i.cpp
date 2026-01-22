class Solution {
public:
    bool sort_check(vector<int> &nums){
        for(int i=0;i<nums.size()-1;i++){
           if(nums[i]>nums[i+1])return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int mini=0;
        int count=0;
        // vector<int> nums;
        // vector<int> check;
        // nums=nums;
        if(nums.size()==1)return 0;
        while(!sort_check(nums)){
            int i=0;
            int sum=nums[0]+nums[1];
            for(int k=1;k<nums.size()-1;k++){
              if(nums[k]+nums[k+1]<sum){
                sum=nums[k]+nums[k+1];
                i=k;
              }
            }
            nums[i]=sum;
            nums.erase(nums.begin()+(i+1));
            count++;
        }
        return count;
    }
};