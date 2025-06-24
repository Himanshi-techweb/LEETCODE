class Solution {
public:
    int solve(int i,int buy,int fee,vector<int> &arr,vector<vector<int>> &dp){
        if(i>=arr.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int profit=solve(i+1,buy,fee,arr,dp);
        if(buy){
          profit= max(-arr[i]+solve(i+1,0,fee,arr,dp),profit);  
        }
        else{
            profit= max(-fee+arr[i]+solve(i+1,1,fee,arr,dp),profit);
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& arr,int fee) {
        int m=arr.size();
       vector<vector<int>> dp(m,vector<int> (2,-1));
       return solve(0,1,fee,arr,dp); 
    }
};