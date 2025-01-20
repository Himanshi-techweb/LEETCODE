class Solution {
public:
    // int solve(vector<vector<char>>&matrix,int i,int j,int &maxi,vector<vector<int>> &dp){
    //     if(i>=matrix.size() || j>=matrix[0].size())return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int right=solve(matrix,i,j+1,maxi,dp);
    //     int down=solve(matrix,i+1,j,maxi,dp);
    //     int diagonal=solve(matrix,i+1,j+1,maxi,dp);
    //     if(matrix[i][j]=='1'){
    //         dp[i][j]=1+min(right,min(down,diagonal));
    //         maxi=max(maxi,dp[i][j]);
    //         return dp[i][j];
    //     }
    //     else{
    //         return dp[i][j]=0;
    //     }
        
    // }
    // int solveTab(vector<vector<char>>&matrix,int &maxi){
    //     int m=matrix.size();
    //     int n=matrix[0].size();
    //     vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    //     // if(i>=matrix.size() || j>=matrix[0].size())return dp[i][j]=0;
    //     // if(dp[i][j]!=-1)return dp[i][j];
    //     for(int i=m-1;i>=0;i--){
    //       for(int j=n-1;j>=0;j--){
    //         int right=dp[i][j+1];
    //         int down=dp[i+1][j];
    //         int diagonal=dp[i+1][j+1];
    //         if(matrix[i][j]=='1'){
    //           dp[i][j]=1+min(right,min(down,diagonal));
    //           maxi=max(maxi,dp[i][j]);
    //         }
    //         else{
    //           dp[i][j]=0;
    //         }
    //       }

    //     }
    //     return dp[1][1];
        
        
    // }
    int solveTab(vector<vector<char>>&matrix,int &maxi){
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);
        // if(i>=matrix.size() || j>=matrix[0].size())return dp[i][j]=0;
        // if(dp[i][j]!=-1)return dp[i][j];
        for(int i=m-1;i>=0;i--){
          for(int j=n-1;j>=0;j--){
            int right=curr[j+1];
            int down=next[j];
            int diagonal=next[j+1];
            if(matrix[i][j]=='1'){
              curr[j]=1+min(right,min(down,diagonal));
              maxi=max(maxi,curr[j]);
            }
            else{
              curr[j]=0;
            }
            
          }
          next=curr;
        }
        return next[1];
        
        
    }//solution in space complexity O(N) where as other solution in O(m*n)
    int maximalSquare(vector<vector<char>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size() ;
    int maxi=0;
    // vector<vector<int>> dp(m,vector<int>(n,-1));
    // solveTab(matrix,maxi); 
    solveTab(matrix,maxi); 
    return maxi*maxi;   
    }
};//Time complexity if O(m*n)