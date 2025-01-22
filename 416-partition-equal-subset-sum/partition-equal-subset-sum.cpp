class Solution {
public:  
    //    bool solve(int i,vector<int> &arr,int tar){
    //     if(i>=arr.size() || tar<0)return 0;
    //     if(tar==0)return 1;
    //     bool include=solve(i+1,arr,tar-arr[i]);
    //     bool exclude=solve(i+1,arr,tar);
    //     return include || exclude; 
    //    } 

    // bool solveMem(int i,vector<int> &arr,int tar,vector<vector<int>>&dp){
    //     if(i>=arr.size() || tar<0)return 0;
    //     if(tar==0)return 1;
    //     if(dp[i][tar]!=-1)return dp[i][tar];
    //     bool include=solveMem(i+1,arr,tar-arr[i],dp);
    //     bool exclude=solveMem(i+1,arr,tar,dp);
    //     return dp[i][tar]= include || exclude; 
    // } 

    // bool solveTab(vector<int> &arr,int tar){
    //     vector<vector<bool>>dp(arr.size()+1,vector<bool>(tar+1,false));
    //     for(int i=0;i<arr.size();i++){
    //         dp[i][0]=true;
    //     }
    //     for(int i=arr.size()-1;i>=0;i--){
    //         for(int j=1;j<=tar;j++){
    //           if((j-arr[i])>=0){
    //             dp[i][j]=dp[i+1][j-arr[i]] || dp[i+1][j];
    //           }
    //           else{
    //             dp[i][j]=dp[i+1][j];
    //           }
    //         }
    //     }
    //     return dp[0][tar];
    // } 
    bool solveTab(vector<int> &arr,int tar){
        // vector<vector<bool>>dp(arr.size()+1,vector<bool>(tar+1,false));
        vector<bool> curr(tar+1,false);
        vector<bool> next(tar+1,false);
        curr[0]=true;
        next[0]=true;
        for(int i=arr.size()-1;i>=0;i--){
            for(int j=1;j<=tar;j++){
              if((j-arr[i])>=0){
                curr[j]=next[j-arr[i]] || next[j];
              }
              else{
                curr[j]=next[j];
              }
            }
            next=curr;
        }
        return next[tar];
    } 

       bool canPartition(vector<int>& nums) {
       int target=0;
       for(int i=0;i<nums.size();i++){
        target+=nums[i];
       } 
       if(target%2!=0)return 0;
        target=target/2;
        // return solve(0,nums,target);
        // vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        // return solveMem(0,nums,target,dp);
        return solveTab(nums,target);
    }
};