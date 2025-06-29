class Solution {
public:
    int stock(int i,int buy,vector<int> &arr,vector<vector<int>> &dp){
      if(arr.size()<=i)return 0;
      if(i==arr.size()-1 && buy==0)return arr[arr.size()-1];
      if(dp[i][buy]!=-1)return dp[i][buy];
      int profit=0;
      if(buy){
        profit=max(stock(i+1,1,arr,dp),-arr[i]+stock(i+1,0,arr,dp));
      }
      else{
        profit=max(stock(i+1,0,arr,dp),arr[i]+stock(i+1,1,arr,dp));
      }  
      return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int> (2,-1));
        return stock(0,1,prices,dp);
    }
};