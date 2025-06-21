class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>> &dp){
        if(i<0 || j<0)return 0;
        if(i==0 && j==0)return dp[0][0]=grid[0][0];
        if(dp[i][j]!=-1)return dp[i][j];
        int left=INT_MAX;
        if(j-1>=0)left= grid[i][j]+solve(i,j-1,grid,dp);
        int right=INT_MAX;
        if(i-1>=0)right=grid[i][j]+solve(i-1,j,grid,dp);
        return dp[i][j]=min(left,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
       vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
       solve(m-1,n-1,grid,dp);
       return dp[m-1][n-1]; 
    }
};