class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>> &arr,vector<vector<int>> &dp){
        if(i<0 || j<0 )return 0;
        if(arr[i][j]==1) return 0;
        if(arr[m-1][n-1]==1)return 0;
        if(i==0 && j==0 )return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int top=solve(i-1,j,m,n,arr,dp);
        int left=solve(i,j-1,m,n,arr,dp);
        return dp[i][j]=top+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        cout<<m<<n<<obstacleGrid[m-1][n-1]<<endl;
        return solve(m-1,n-1,m,n,obstacleGrid,dp);
    }
};