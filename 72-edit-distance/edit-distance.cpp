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
      vector<vector<int>> dp(q1+1,vector<int> (q2+1,-1));
      return solve(q1,q2,word1,word2,dp);  
    }
};