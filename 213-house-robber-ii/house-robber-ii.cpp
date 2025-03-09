class Solution {
public:
    int solve(int i,int e,vector<int> &arr,vector<int> &dp){
        if(i>=e)return 0;
        if(dp[i]!=-1)return dp[i];
        int include=solve(i+2,e,arr,dp)+arr[i];
        int exclude=solve(i+1,e,arr,dp)+0;
        return dp[i]=max(include,exclude);
    }
    int rob(vector<int>& nums) {
      int n=nums.size();
      if(n==1)return nums[0];
      vector<int> dp1(n+1,-1);
      vector<int> dp2(n+1,-1);  
      return max(solve(0,n-1,nums,dp1),solve(1,n,nums,dp2));
    }
};