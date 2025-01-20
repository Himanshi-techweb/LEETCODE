class Solution {
public:
    // int solveMemo(vector<int> &arr,int i,int time,vector<vector<int>> &dp){
    //    if(i>=arr.size())return 0;
    //    if(dp[i][time]!=-1)return dp[i][time];
    //    int include=arr[i]*(time+1)+solve(arr,i+1,time+1,dp);
    //    int exclude=solve(arr,i+1,time,dp);
    //    dp[i][time]=max(include,exclude);
    //    return dp[i][time]; 
    // }
    // int solveTab(vector<int> &arr){
    //     int n=arr.size();
    //     vector<vector<int>>dp(n+1,vector<int> (n+1,0));
    //     for(int i=n-1;i>=0;i--){
    //         for(int time=n-1;time>=0;time--){
    //             int include=arr[i]*(time+1)+dp[i+1][time+1];
    //             int exclude=dp[i+1][time];
    //             dp[i][time]=max(include,exclude);
    //         }
    //     }
    //     return dp[0][0];
    // }
    int solveTab(vector<int> &arr){
        int n=arr.size();
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int time=n-1;time>=0;time--){
                int include=arr[i]*(time+1)+next[time+1];
                int exclude=next[time];
                curr[time]=max(include,exclude);
            }next=curr;
        }
        return next[0];
    }
    int maxSatisfaction(vector<int>& arr) {
      vector<vector<int>> dp(arr.size(),vector<int>(arr.size(),-1));
      sort(arr.begin(),arr.end());
      int ans=solveTab(arr);
      return ans;
    }
};