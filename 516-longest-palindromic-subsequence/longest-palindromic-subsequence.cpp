class Solution {
public:
int longestPalindromeSubseq(string s) {       
       string text1=s;
       reverse(s.begin(),s.end());
       string text2=s;
        int n1=text1.size();
       int n2=text1.size();
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