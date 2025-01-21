class Solution {
public:
    // int solve(vector<int> &arr,int prev,int curr,int &n,vector<vector<int>> &dp){
    //     if(curr>=n)return 0;
    //     if(dp[curr][prev+1]!=-1)return dp[curr][prev+1];
    //     int include=0;
    //     if(prev==-1 || arr[curr]>arr[prev]){
    //         include=1+solve(arr,curr,curr+1,n,dp);
    //     }
    //     int exclude=solve(arr,prev,curr+1,n,dp);
    //     dp[curr][prev+1]=max(include,exclude);
    //     return max(include,exclude);
    // }
    int solveTab(vector<int> &arr,int n){
       vector<vector<int>>dp(n+1,vector<int>(n+1,0));
       for(int curr=n-1;curr>=0;curr--){
        for(int prev=curr-1;prev>=-1;prev--){
            int include=0;
            if(prev==-1 || arr[curr]>arr[prev]){
                include=1+dp[curr+1][curr+1];
            }
            int exclude=dp[curr+1][prev+1];
            dp[curr][prev+1]=max(include,exclude);
        }
       }
       return dp[0][0];
    }
    int lengthOfLIS(vector<int>& nums) {
      int n=nums.size();
    //   vector<vector<int>>dp(n,vector<int> (n+1,-1));
    //   return solve(nums,-1,0,n,dp);  
    return solveTab(nums,n);
    }
};