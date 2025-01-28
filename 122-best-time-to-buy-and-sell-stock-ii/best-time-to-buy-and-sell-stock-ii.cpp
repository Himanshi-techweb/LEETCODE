class Solution {
public:
    int solve(int index,int buy,vector<int> &arr,vector<vector<int>> &dp){
        if(index==arr.size()){
            return 0;
        }
        if(dp[index][buy]!=-1)return dp[index][buy];
        long long profit=0;
        if(buy){
             profit=max(-arr[index]+solve(index+1,0,arr,dp),0+solve(index+1,1,arr,dp));
        }
        else{
             profit=max(arr[index]+solve(index+1,1,arr,dp),0+solve(index+1,0,arr,dp));
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        // vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        dp[prices.size()][0]=dp[prices.size()][1]=0;
        for(int index=prices.size()-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                long long profit=0;
                if(buy){
                   profit=max(-prices[index]+dp[index+1][0],0+dp[index+1][1]);
                }
                else{
                   profit=max(prices[index]+dp[index+1][1],0+dp[index+1][0]);
                }
                dp[index][buy]=profit;
            }
        }
        return dp[0][1];
    //    return solve(0,1,prices,dp); 
    }
};