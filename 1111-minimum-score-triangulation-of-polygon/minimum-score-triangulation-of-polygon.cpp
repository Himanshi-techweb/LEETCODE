class Solution {
public:
    int solve(vector<int> &arr,int i,int j,vector<vector<int>> &dp,int &ans){
        if(i+1==j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int minscore=INT_MAX;
        for(int k=i+1;k<j;k++){
          dp[i][j]=min(minscore,arr[i]*arr[j]*arr[k]+solve(arr,i,k,dp,ans)+solve(arr,k,j,dp,ans));
          minscore=min(dp[i][j],minscore);
          ans=minscore;
        }
        return minscore;
    }
    int minScoreTriangulation(vector<int>& values) {
        int x=values.size();
        int ans=INT_MAX;
        vector<vector<int>>dp(x,vector<int>(x,-1));
       solve(values,0,values.size()-1,dp,ans);
       return ans; 
    }
};