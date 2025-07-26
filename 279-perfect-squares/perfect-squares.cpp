class Solution {
public:
    int solve(int i,vector<int> &dp){
        if(i<=0)return 0;
        if(i==1)return 1;
        if(dp[i]!=-1)return dp[i];
        int mini=INT_MAX;
        for(int k=1;k<=sqrt(i);k++){
           mini=min(mini,1+solve(i-k*k,dp));
        }
        return dp[i]=mini;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
       return solve(n,dp); 
    }
};