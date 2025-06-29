class Solution {
public:
    long long solve(int i,int cnt,int k,vector<int> &arr,vector<vector<vector<long long>>> &dp){
        if(i>=arr.size())return 0;
        if(k==0)return 0;
        if(dp[i][cnt][k]!=-1)return dp[i][cnt][k];
        if(i==arr.size()-1){
            if(cnt==0)return 0;
            if(cnt==1)return arr[i];
            if(cnt==2)return -arr[i];
        }
        long long profit=INT_MIN;
        if(cnt==0){
            profit=max(profit,-arr[i]+solve(i+1,1,k,arr,dp));
            profit=max(profit,solve(i+1,0,k,arr,dp));
            profit=max(profit,arr[i]+solve(i+1,2,k,arr,dp));
        }
        else if(cnt==1){
            profit=max(profit,arr[i]+solve(i+1,0,k-1,arr,dp));
            profit=max(profit,solve(i+1,1,k,arr,dp));
        }
        else{
            profit=max(profit,-arr[i]+solve(i+1,0,k-1,arr,dp));
            profit=max(profit,solve(i+1,2,k,arr,dp));
        }
        return dp[i][cnt][k]=profit;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        // vector<vector<int
        vector<vector<vector<long long>>> dp(prices.size()+1,vector<vector<long long>> (3,vector<long long> (k+1,-1)));
        return solve(0,0,k,prices,dp);
    }
};