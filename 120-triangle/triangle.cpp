class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>> &dp){
        if(i<0 || j<0 || j>i)return INT_MAX;
        if(i==0 && j==0 )return dp[i][j]=grid[0][0];
        if(dp[i][j]!=-1)return dp[i][j];
        int left=solve(i-1,j-1,grid,dp);
        int right=solve(i-1,j,grid,dp);
        return dp[i][j]=grid[i][j]+min(left,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
       int m=triangle.size();
       int n=triangle[m-1].size();
       vector<vector<int>> dp(m,vector<int>(n,-1));
       int ans=INT_MAX;
       for(int i=0;i<triangle[m-1].size();i++){
         dp[m-1][i]=solve(m-1,i,triangle,dp);
       }
       return *min_element(dp[m-1].begin(),dp[m-1].end());
    }
    
};