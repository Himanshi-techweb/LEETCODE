class Solution {
public:
    int nextindex(int i,int cnt,vector<int> &day){
        int curr=day[i]+cnt;
        auto next=lower_bound(day.begin(),day.end(),curr);
        return next-day.begin();
    }
    int solve(int i,vector<int> &day,vector<int> &cost,int n,vector<int> &dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        //if person take  1 day ticket then can travel max to arr[i];
        int take_1=cost[0]+solve(nextindex(i,1,day),day,cost,n,dp);
        int take_7=cost[1]+solve(nextindex(i,7,day),day,cost,n,dp);
        int take_30=cost[2]+solve(nextindex(i,30,day),day,cost,n,dp);
        return dp[i]=min({take_1,take_7,take_30});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n+1,-1);
        return solve(0,days,costs,n,dp); 
    }
};