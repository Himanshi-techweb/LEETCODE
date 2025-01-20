class Solution {
public:
    int solve(vector<int> &arr,int i,int j,vector<vector<int>>&dp){
        if(i+1==j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mscore=INT_MAX;
        for(int k=i+1;k<j;k++){
          dp[i][j]=min(mscore,arr[i]*arr[j]*arr[k]+solve(arr,i,k,dp)+solve(arr,k,j,dp));
          mscore=min(dp[i][j],mscore);
        }
        return mscore;
    }
    int minScoreTriangulation(vector<int>& values) {
       int x=values.size();
       vector<vector<int>>dp(x,vector<int>(x,-1));
       int ans=solve(values,0,values.size()-1,dp);
       return ans; 
    }
};