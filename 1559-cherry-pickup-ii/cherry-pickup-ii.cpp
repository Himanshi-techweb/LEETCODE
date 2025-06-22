class Solution {
public: 
    vector<int> change={-1,0,1};
    int solve(int i,int j1,int j2,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        int m=grid.size();int n=grid[0].size();
        if(i>=m || j1<0 ||j1>=n || j2<0 || j2>=n){
            return INT_MIN;
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        if(j1==j2)return grid[i][j1];
        if(i==m-1){
            return grid[i][j1]+grid[i][j2];
        }  
        int maxi=INT_MIN;
        for(int k=0;k<3;k++){
           for(int j=0;j<3;j++){
             maxi=max(maxi,solve(i+1,j1+change[k],j2+change[j],grid,dp));
           } 
        }
        int curr=(j1==j2)?grid[i][j1]:grid[i][j1]+grid[i][j2];
        return dp[i][j1][j2]=curr+maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        return solve(0,0,n-1,grid,dp);
        
    }
};