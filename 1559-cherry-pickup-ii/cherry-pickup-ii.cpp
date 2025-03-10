class Solution {
public:
    int solve(int i,int j1,int j2,int m,int n,vector<vector<int>> &arr,vector<vector<vector<int>>> &dp){
        if(j1<0 || j1>=n || j2<0 || j2>=n)return -1e8;
        if(i==m-1){
            if(j1==j2)return arr[i][j1];
            else return arr[i][j1]+arr[i][j2];
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        int check=-1e8;
        for(int q=-1;q<=1;q++){
            for(int r=-1;r<=1;r++){
               int x=0;
               if(j1==j2){
                //  check=max(check,solve(i+1,j1+q,j2+r,m,n,arr,dp))+arr[i][j1];
                x=arr[i][j1];
               } else{
                // check=max(check,solve(i+1,j1+q,j2+r,m,n,arr,dp))+arr[i][j1]+arr[i][j2];
                x=arr[i][j2]+arr[i][j1];
               }
               x+=solve(i+1,j1+q,j2+r,m,n,arr,dp);
               check=max(check,x);
            }
        }
        return dp[i][j1][j2]=check;
    }
    int cherryPickup(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size(); 
       vector<vector<vector<int>>> matrix(m,vector<vector<int>> (n,vector<int>(n,-1)));
       return solve(0,0,n-1,m,n,grid,matrix);
    }
};