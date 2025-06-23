class Solution {
public:
    int solve(int i,int j,string x,string y,vector<vector<int>> &dp){
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(x[i]==y[j])return 1+solve(i-1,j-1,x,y,dp);
        int left=INT_MIN;int right=INT_MIN;
        left=solve(i-1,j,x,y,dp);
        right=solve(i,j-1,x,y,dp);
        return dp[i][j]= max(left,right);
    }
    int longestCommonSubsequence(string x, string y) {
       int m=x.size();
       int n=y.size();
       vector<vector<int>> dp(m+1,vector<int> (n+1,0));
       vector<int> prev(n+1,0);
    //    return solve(i-1,j-1,text1,text2,dp);
        for(int i=0;i<=m;i++){
            dp[i][0]=0;
        } 
        for(int j=0;j<=n;j++){
            dp[0][j]=0;
        } 
        for(int i=1;i<=m;i++){
          for(int j=1;j<=n;j++){
            if(x[i-1]==y[j-1])dp[i][j]= 1+dp[i-1][j-1];
            else{
              int left=INT_MIN;int right=INT_MIN;
              left=dp[i-1][j];
              right=dp[i][j-1];
              dp[i][j]= max(left,right);
            }
          }
        }
        return dp[m][n];
    }
};