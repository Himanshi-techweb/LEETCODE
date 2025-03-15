class Solution {
public:
    string shortestCommonSupersequence(string t1, string t2) {
       int n1=t1.size();
       int n2=t2.size();
       vector<vector<int>> dp(n1+1,vector<int> (n2+1,0)); 
       for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
           if(t1[i-1]==t2[j-1]){
           dp[i][j]=1+dp[i-1][j-1];
           }
           else dp[i][j]=max(dp[i][j-1],dp[i-1][j]); 
        }
      }
      int k=n1+n2-dp[n1][n2];
      string ans="";
      int i=n1;int j=n2;
      while(i>0 && j>0){
        if(t1[i-1]==t2[j-1]){
            ans.push_back(t1[i-1]);
            i--;
            j--;
            
        }
        else {
            if(dp[i-1][j]>=dp[i][j-1]){
                ans.push_back(t1[i-1]);
                i--;
               
            }
            else{
                 ans.push_back(t2[j-1]);
                j--;
                
            }
        }
      }
      while(i>0){
        ans.push_back(t1[i-1]);
        i--;
       
      }
      while(j>0){
        ans.push_back(t2[j-1]);
        j--;
        
      }
      reverse(ans.begin(),ans.end());
      return ans;

    }
};