class Solution {
public:
    int solve(int i,bool buy,vector<int> &price,vector<vector<int>> &dp){
        if(i==price.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int profit=0;
        if(buy){
            profit=max(-price[i]+solve(i+1,0,price,dp),0+solve(i+1,1,price,dp));
        }
        else{
            profit=max(price[i]+solve(i+1,1,price,dp),0+solve(i+1,0,price,dp));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& price) {
        vector<vector<int>> dp(price.size()+1,vector<int> (2,0));
        int n=price.size();
        //return solve(0,1,prices,dp);
        dp[n][0]=0;
        dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
               int profit=0;
                if(buy){
                   profit=max(-price[i]+dp[i+1][0],0+dp[i+1][1]);
                }
                else{
                   profit=max(price[i]+dp[i+1][1],0+dp[i+1][0]);
                }
                dp[i][buy]=profit;
            }
        }
        return dp[0][1];
    }
};