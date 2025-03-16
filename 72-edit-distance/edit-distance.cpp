class Solution {
public:
    int solve(int i,int j,string t1,string t2,vector<vector<int>> &dp){
        if(i==0 )return j;
        if(j==0 )return i;//here following 1 based indexing if 0 based indexing then add 1 to both base case 
        if(dp[i][j]!=-1)return dp[i][j];
        //if match
        if(t1[i-1]==t2[j-1]){
            dp[i][j]=solve(i-1,j-1,t1,t2,dp);
        }
        //if not match then /////insert,remove,replace
        else{
            dp[i][j]=min({1+solve(i,j-1,t1,t2,dp),1+solve(i-1,j,t1,t2,dp),1+solve(i-1,j-1,t1,t2,dp)});
        }return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int q1=word1.size();int q2=word2.size();
      vector<vector<int>> dp(q1+1,vector<int> (q2+1,0));
      //return solve(q1,q2,word1,word2,dp);  
      for(int i=0;i<=q1;i++){
        dp[i][0]=i;
      }
      for(int j=0;j<=q2;j++){
        dp[0][j]=j;
      }////////////////////////////////////////////////////////////////////space optimization
      vector<int> prev(q2+1,0);
      for(int i=0;i<=q2;i++){
        prev[i]=i;
      }
      for(int i=0;i<=q2;i++){
        prev[i]=i;
      }
      vector<int> curr(q2+1,0);
      //curr[0]=1;
      for(int i=1;i<=q1;i++){
        curr[0]=i;
      for(int j=1;j<=q2;j++){
            if(word1[i-1]==word2[j-1]){
                curr[j]=prev[j-1];
            }
            else{
                curr[j]=min({1+curr[j-1],1+prev[j],1+prev[j-1]});
            }
        }
        prev=curr;
      }
      return prev[q2];
    }
};