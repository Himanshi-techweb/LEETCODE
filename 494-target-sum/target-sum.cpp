class Solution {
public:
    int solve(int i,int tar,vector<int>&arr,vector<vector<int>> &dp){
        if(i==0){
            if(arr[0]==0 && tar==0)return 2;
            else if(tar==0 || arr[0]==tar)return 1;
            else return 0;
        }
        if(dp[i][tar]!=-1)return dp[i][tar];
        int nottake=solve(i-1,tar,arr,dp);
        int take=0;
        if(arr[i]<=tar)take=solve(i-1,tar-arr[i],arr,dp);
        return dp[i][tar]=(take+nottake);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
       int sum=accumulate(nums.begin(),nums.end(),0);
       int n=nums.size();
       int tar=target+sum;
       if(tar%2!=0 || tar<0)return 0;
       tar=tar/2;
       vector<vector<int>> dp(n,vector<int> (tar+1,-1));
       return solve(n-1,tar,nums,dp);
       
    }
};