class Solution {
public:
    int minInsertions(string s) {
      string t1=s;
      reverse(s.begin(),s.end());
      string t2=s;
      int k=s.size();
      vector<vector<int>>dp(k+1,vector<int> (k+1,0));
      for(int i=0;i<=k;i++){
        dp[0][i]=0;
        dp[i][0]=0;
      }
      for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            if(t1[i-1]==t2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
      } 
      return k-dp[k][k];
    }

};