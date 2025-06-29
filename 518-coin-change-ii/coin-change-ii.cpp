class Solution {
public:
    long long solve(int i,int amount,vector<int> &arr,vector<vector<int>> &dp){
        if(i==0){
            if(amount%arr[0]==0) return 1;
            return 0;
        }
        if(dp[i][amount]!=-1)return dp[i][amount];
        long long take=0;
        if(arr[i]<=amount)take=solve(i,amount-arr[i],arr,dp);
        long long nottake=solve(i-1,amount,arr,dp);
        return dp[i][amount]=take+nottake; 
    }
    int change(int amount,vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));
        return solve(coins.size()-1,amount,coins,dp);
    }
};