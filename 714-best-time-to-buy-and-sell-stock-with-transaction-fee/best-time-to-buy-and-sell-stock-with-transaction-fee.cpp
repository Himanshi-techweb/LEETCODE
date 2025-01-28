class Solution {
public:
   int solve(int index,int buy,vector<int> &arr,vector<vector<int>>&dp,int tran){
    if(index==arr.size()){
        return 0;
    }
    if(dp[index][buy]!=-1)return dp[index][buy];
    long long profit=0;
    if(buy){
        profit=max(-arr[index]+solve(index+1,0,arr,dp,tran),solve(index+1,1,arr,dp,tran));
    }
    else{
        profit=max(arr[index]-tran+solve(index+1,1,arr,dp,tran),solve(index+1,0,arr,dp,tran));
    }
    return dp[index][buy]=profit;
   }
    int maxProfit(vector<int>& prices, int fee) {
       vector<vector<int>> dp(prices.size(),vector<int> (2,-1));
       return solve(0,1,prices,dp,fee);  
    }
};