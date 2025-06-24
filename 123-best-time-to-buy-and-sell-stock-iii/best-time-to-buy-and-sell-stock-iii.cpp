class Solution {
public:
    int solve(int i,int buy,int k,vector<int> &arr,vector<vector<vector<int>>> &dp){
        if(i==arr.size())return 0;
        if(k>=2)return 0;
        if(dp[i][buy][k]!=-1)return dp[i][buy][k];
        int profit=0;
        if(buy){
            profit=max(-arr[i]+solve(i+1,0,k,arr,dp),solve(i+1,1,k,arr,dp));
        }
        else{
            profit=max(arr[i]+solve(i+1,1,k+1,arr,dp),solve(i+1,0,k,arr,dp));
        }
        return dp[i][buy][k]=profit;
    }
    int maxProfit(vector<int>& price) {
        vector<vector<vector<int>>> dp(price.size(),vector<vector<int>>(2,vector<int> (2,-1)));
       return solve(0,1,0,price,dp);
    }
};