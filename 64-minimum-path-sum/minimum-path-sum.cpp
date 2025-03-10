class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &arr,vector<vector<int>> &dp){
        if(i<0 || j<0)return 1e9;
        if(i==0 && j==0 )return arr[0][0];
        if(dp[i][j]!=-1)return dp[i][j];
        int top=0;
        int left=0;
           top=solve(i-1,j,arr,dp)+arr[i][j];
           left=solve(i,j-1,arr,dp)+arr[i][j];
        
        return dp[i][j]=min(top,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
       vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
       return solve(m-1,n-1,grid,dp); 
    }
};