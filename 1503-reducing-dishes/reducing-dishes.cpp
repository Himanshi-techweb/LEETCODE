class Solution {
public:
    int solve(vector<int> &arr,int i,int time,vector<vector<int>> &dp){
       if(i>=arr.size())return 0;
       if(dp[i][time]!=-1)return dp[i][time];
       int include=arr[i]*(time+1)+solve(arr,i+1,time+1,dp);
       int exclude=solve(arr,i+1,time,dp);
       dp[i][time]=max(include,exclude);
       return dp[i][time]; 
    }
    int maxSatisfaction(vector<int>& arr) {
      vector<vector<int>> dp(arr.size(),vector<int>(arr.size(),-1));
      sort(arr.begin(),arr.end());
      int ans=solve(arr,0,0,dp);
      return ans;
    }
};