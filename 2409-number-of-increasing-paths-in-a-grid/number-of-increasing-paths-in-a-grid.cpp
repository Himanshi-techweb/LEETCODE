class Solution {
public:
    long long cnt=0;
    const int MOD=1e9+7;
    vector<vector<int>> rc={{-1,0},{0,-1},{0,1},{1,0}};
    long long dfs(int row,int col,vector<vector<int>> &arr,vector<vector<int>> &visit,vector<vector<long long>> &dp){
        long long ans=0;
        if(dp[row][col]!=-1)return dp[row][col];
        for(auto it:rc){
            int nr=row+it[0];int nc=col+it[1];
            if(nr>=0 && nr<arr.size() && nc>=0 && nc<arr[0].size() && arr[row][col]<arr[nr][nc]){
            //   visit[nr][nc]=1;
              ans=(ans+(1+dfs(nr,nc,arr,visit,dp)%MOD))%MOD; 
            //   visit[nr][nc]=0;
            }
        }
        return dp[row][col]=ans%MOD;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size();int n=grid[0].size();
        vector<vector<long long>> dp(m,vector<long long>(n,-1));
         vector<vector<int>> visit(grid.size(),vector<int> (grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                // visit[i][j]=1;
                cnt=(cnt+1+dfs(i,j,grid,visit,dp)%MOD)%MOD;
            }
        }
        return cnt;
    }
};