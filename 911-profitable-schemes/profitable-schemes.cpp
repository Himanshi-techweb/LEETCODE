class Solution {
public:
    int ans=0;
    const int MOD=1e9+7;
    int solve(int i,int minProfit,vector<int> &group ,vector<int> &profit,int &curr,int &total,int n,vector<vector<vector<int>>> &dp){
        if(total>n)return 0;
        if(i==group.size()){
           if(curr>=minProfit )return 1;
           return 0;
        }
        int profitcurr=min(minProfit,curr);
        if(dp[i][profitcurr][total]!=-1)return dp[i][profitcurr][total];
        
        int take=0;
        if(total+group[i]<=n){
           total=total+group[i];curr=curr+profit[i];
           take=solve(i+1,minProfit,group,profit,curr,total,n,dp);
           total=total-group[i];curr=curr-profit[i];
        }
        int nottake=solve(i+1,minProfit,group,profit,curr,total,n,dp);
        return dp[i][profitcurr][total]=(take+nottake)%MOD;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
       int curr=0;int total=0;
       int curr_sum=0;
       for(auto it:profit)curr_sum+=it;
       vector<vector<vector<int>>> dp(profit.size(),vector<vector<int>> (curr_sum+1,vector<int> (n+1,-1)));
       return solve(0,minProfit,group,profit,curr,total,n,dp);
    //    return ans; 
    }
};