class Solution {
public:
    int solve(int i1,int i2,string &text1, string &text2,vector<vector<int>>&dp){
        if(i1<0 || i2<0)return 0;
       if(dp[i1][i2]!=-1)return dp[i1][i2];
       //match
    //    int match=-1e9;
    //    if(text1[i1]==text2[i2]){
    //     match=1+solve(i1-1,i2-1,text1,text2,dp);
    //    }
    //    //not match
    //    int notmatch=max(solve(i1,i2-1,text1,text2,dp),solve(i1-1,i2,text1,text2,dp));
    //    return dp[i1][i2]=max(match,notmatch);
       if(text1[i1]==text2[i2]){
        return dp[i1][i2]=1+solve(i1-1,i2-1,text1,text2,dp);
       }
       //not match
       return dp[i1][i2]=max(solve(i1,i2-1,text1,text2,dp),solve(i1-1,i2,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
       int n1=text1.size();
       int n2=text2.size();
       vector<vector<int> >dp(n1+1,vector<int> (n2+1,0));
       //return solve(n1-1,n2-1,text1,text2,dp);
      for(int i=0;i<=n2;i++){
        dp[0][i]=0;
      }
      for(int i=0;i<=n1;i++){
        dp[i][0]=0;
      } 
      for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
           if(text1[i-1]==text2[j-1]){
           dp[i][j]=1+dp[i-1][j-1];
           }
           else dp[i][j]=max(dp[i][j-1],dp[i-1][j]); 
        }
      } 
      return dp[n1][n2];
    }
};