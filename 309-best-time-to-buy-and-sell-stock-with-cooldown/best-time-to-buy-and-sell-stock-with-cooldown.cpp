class Solution {
public:
    int solve(int i,int buy,vector<int> &arr,vector<vector<int>> &dp){
        if(i>=arr.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int bought=0;int sell=0;
        if(buy){
          bought= max(-arr[i]+solve(i+1,0,arr,dp),solve(i+1,1,arr,dp));  
        }
        else{
            sell= max(arr[i]+solve(i+2,1,arr,dp),solve(i+1,0,arr,dp));
        }
        return dp[i][buy]=max(bought,sell);
    }
    int maxProfit(vector<int>& arr) {
        int m=arr.size();
       vector<vector<int>> dp(m,vector<int> (2,-1));
       return solve(0,1,arr,dp); 
    }
};