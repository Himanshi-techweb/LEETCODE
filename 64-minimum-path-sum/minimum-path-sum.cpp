class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &arr,vector<vector<int>> &dp){
        if(i==0 && j==0)return arr[0][0];
        if(i<0 || j<0)return INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        int left=INT_MAX;
        if(j-1>=0)left=solve(i,j-1,arr,dp);
        int right=INT_MAX;
        if(i-1>=0)right=solve(i-1,j,arr,dp);
        return dp[i][j]=arr[i][j]+min(left,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size(); 
       vector<vector<int>> dp(m,vector<int> (n,-1));
       return solve(m-1,n-1,grid,dp);

    }
};