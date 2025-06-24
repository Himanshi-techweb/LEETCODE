class Solution {
public:
    long long solve(int i,int holding,int k,vector<int> &arr,vector<vector<vector<long long>>> &dp){
        if(k==0)return 0;
        if(i==arr.size())return 0;
        if(i==arr.size()-1){
            if(holding==0)return 0;
            if(holding==1)return arr[i];
            return -arr[i];
        };
        if(dp[i][holding][k]!=-1)return dp[i][holding][k];
        long long profit=INT_MIN;
        profit=max(profit,solve(i+1,holding,k,arr,dp));
        if(holding==0){
            profit=max(profit,-arr[i]+solve(i+1,1,k,arr,dp));
            profit=max(profit,arr[i]+solve(i+1,2,k,arr,dp));
        }
        else if(holding==1){
            profit=max(profit,arr[i]+solve(i+1,0,k-1,arr,dp));
        }
        else{
            profit=max(profit,-arr[i]+solve(i+1,0,k-1,arr,dp));
        }
        return dp[i][holding][k]=profit;
    }
    long long maximumProfit(vector<int>& price,int k) {
        vector<vector<vector<long long>>> dp(price.size(),vector<vector<long long>>(4,vector<long long> (k+1,-1)));
       return solve(0,0,k,price,dp);
    }
};