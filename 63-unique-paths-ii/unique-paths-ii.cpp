class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&arr, vector<vector<int>> &dp){
        if(i<0 || j<0)return 0;
        if(i==0 && j==0)return dp[0][0]=1;
        // if(dp[i][j]==1)return dp[i][j]=0;
        if(dp[i][j]!=-1)return dp[i][j];
        int left=0;int right=0;
        if(i-1>=0 && arr[i-1][j]==0){
            left=solve(i-1,j,arr,dp);
        }
        if(j-1>=0 && arr[i][j-1]==0){
            right=solve(i,j-1,arr,dp);
        }
        return dp[i][j]=left+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
       if(grid[0][0]==1 || grid[m-1][n-1]==1)return 0;
       vector<vector<int>> dp(m+1,vector<int> (n,-1));
       solve(m-1,n-1,grid,dp);
       return dp[m-1][n-1];
    }
};