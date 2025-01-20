class Solution {
public:
    int solve(vector<int> &arr,int i,int j,vector<vector<int>> &dp){
        if(i+1==j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int minscore=INT_MAX;
        for(int k=i+1;k<j;k++){
          dp[i][j]=min(minscore,arr[i]*arr[j]*arr[k]+solve(arr,i,k,dp)+solve(arr,k,j,dp));
          minscore=min(dp[i][j],minscore);
        }
        return minscore;
    }
    int minScoreTriangulation(vector<int>& values) {
        int x=values.size();
        vector<vector<int>>dp(x,vector<int>(x,-1));
       int ans=solve(values,0,values.size()-1,dp);
       return ans; 
    }
};