class Solution {
public:  
    //    bool solve(int i,vector<int> &arr,int tar){
    //     if(i>=arr.size() || tar<0)return 0;
    //     if(tar==0)return 1;
    //     bool include=solve(i+1,arr,tar-arr[i]);
    //     bool exclude=solve(i+1,arr,tar);
    //     return include || exclude; 
    //    } 

    bool solveMem(int i,vector<int> &arr,int tar,vector<vector<int>>&dp){
        if(i>=arr.size() || tar<0)return 0;
        if(tar==0)return 1;
        if(dp[i][tar]!=-1)return dp[i][tar];
        bool include=solveMem(i+1,arr,tar-arr[i],dp);
        bool exclude=solveMem(i+1,arr,tar,dp);
        return dp[i][tar]= include || exclude; 
    } 

       bool canPartition(vector<int>& nums) {
       int target=0;
       for(int i=0;i<nums.size();i++){
        target+=nums[i];
       } 
       if(target%2!=0)return 0;
        target=target/2;
        // return solve(0,nums,target);
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        return solveMem(0,nums,target,dp);
    }
};