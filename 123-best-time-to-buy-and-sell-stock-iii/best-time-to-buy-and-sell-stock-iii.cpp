class Solution {
public:
    int solve(int i,bool buy,int k,vector<int> &price,vector<vector<vector<int>>> &dp){
        if(i==price.size())return 0;
        if(k>=2)return 0;
        if(dp[i][buy][k]!=-1)return dp[i][buy][k];
        int profit=0;
        if(buy){
            profit=max(-price[i]+solve(i+1,0,k,price,dp),0+solve(i+1,1,k,price,dp));
        }
        else{
            profit=max(price[i]+solve(i+1,1,k+1,price,dp),0+solve(i+1,0,k,price,dp));
        }
        return dp[i][buy][k]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(2,-1))); 
        return solve(0,1,0,prices,dp); 
    }
};