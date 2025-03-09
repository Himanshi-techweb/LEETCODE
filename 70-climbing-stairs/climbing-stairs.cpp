class Solution {
public:
    int climb(int n,vector<int> &dp){
        if(n==0)return 1;
        if(n==1)return 1;
        if(dp[n]!=-1)return dp[n];
        int j1=climb(n-1,dp);
        int j2=climb(n-2,dp);
        return dp[n]=j1+j2;
    }
    int climbStairs(int n) {
      vector<int> dp(n+1,-1);
      return climb(n,dp);   
    }
};