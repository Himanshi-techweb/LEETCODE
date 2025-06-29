class Solution {
public: 
    long long solve(int i,int amount,vector<int> &arr,vector<vector<int>> &dp){
        if(i==0){
            if(amount%arr[0]==0) return amount/arr[0];
            return INT_MAX;
        }
        if(dp[i][amount]!=-1)return dp[i][amount];
        long long take=INT_MAX;
        if(arr[i]<=amount)take=1+solve(i,amount-arr[i],arr,dp);
        long long nottake=solve(i-1,amount,arr,dp);
        return dp[i][amount]=min(take,nottake); 
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));
        return ((solve(coins.size()-1,amount,coins,dp)!=INT_MAX))?solve(coins.size()-1,amount,coins,dp):-1;
    }
};