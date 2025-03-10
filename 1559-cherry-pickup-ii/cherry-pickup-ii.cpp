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
    // int cherryPickup(vector<vector<int>>& grid) {
    //    int m=grid.size();
    //    int n=grid[0].size(); 
    //    vector<vector<vector<int>>> matrix(m,vector<vector<int>> (n,vector<int>(n,-1)));
    //    return solve(0,0,n-1,m,n,grid,matrix);
    // }
    int cherryPickup(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size(); 
       vector<vector<vector<int>>> dp(m,vector<vector<int>> (n,vector<int>(n,0)));
       for(int j1=0;j1<n;j1++){
        for(int j2=0;j2<n;j2++){
            if(j1==j2)dp[m-1][j1][j2]=grid[m-1][j1];
            else dp[m-1][j1][j2]=grid[m-1][j1]+grid[m-1][j2];
        }
       }
       for(int i=m-2;i>=0;i--){
        for(int j1=0;j1<n;j1++){
            for(int j2=0;j2<n;j2++){
                int check=-1e8;
                for(int q=-1;q<=1;q++){
                for(int r=-1;r<=1;r++){
                  int x=0;
                  if(j1==j2){
                    x=grid[i][j1];
                  } 
                  else{
                    x=grid[i][j2]+grid[i][j1];
                  }
            //    x+=solve(i+1,j1+q,j2+r,m,n,arr,dp);
                 if(j1+q>=0 && j1+q<n && j2+r>=0 && j2+r<n ){
                   x+=dp[i+1][j1+q][j2+r];
                 } 
                 else {
                   x+=-1e8;
                 }
                 check=max(check,x);
            }
            }
            dp[i][j1][j2]=check; 
            }
        }
       }
       return dp[0][0][n-1];
    }
};