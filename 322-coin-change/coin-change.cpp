class Solution {
public:
    int solve(int i,int a,vector<int> arr,vector<vector<int>>&dp){
        if(i==0){
             if(a%arr[0]==0)return a/arr[0];
            else return 1e9; 
        }
        if(dp[i][a]!=-1)return dp[i][a];
        int take=1e9;
        if(arr[i]<=a){
            take=1+solve(i,a-arr[i],arr,dp);
        }
        int nottake=solve(i-1,a,arr,dp);
        return dp[i][a]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        int ans= solve(n-1,amount,coins,dp);
        return (ans>=1e9)?-1:ans;
    }
};