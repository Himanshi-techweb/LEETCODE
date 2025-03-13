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
    int coinChange(vector<int>& arr, int amount) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,1e9));
        // int ans= solve(n-1,amount,coins,dp);
        // return (ans>=1e9)?-1:ans;
        
        dp[0][0]=0;
        for(int i=arr[0];i<=amount;i++){
            if(i%arr[0]==0)dp[0][i]=i/arr[0];
            else dp[0][i]=1e9;
        }
        
        for(int i=1;i<n;i++){
            for(int a=0;a<=amount;a++){
                int take=1e9;
                if(arr[i]<=a)take=1+dp[i][a-arr[i]];
                int nottake=dp[i-1][a];
                dp[i][a]=min(take,nottake);
            }
        }
         int ans= dp[n-1][amount];
         return (ans>=1e9)?-1:ans;
    }
};