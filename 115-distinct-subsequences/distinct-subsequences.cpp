class Solution {
public:
    int solve(int i,int j,string t1,string t2, vector<vector<int>> &dp){
        if(j<=0)return 1;
        if(i<=0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(t1[i-1]==t2[j-1]){
           return  dp[i][j]=solve(i-1,j-1,t1,t2,dp)+solve(i-1,j,t1,t2,dp);
        }
        else{
            return dp[i][j]=solve(i-1,j,t1,t2,dp);
        }
    }
    int numDistinct(string t1, string t2) {
       int q1=t1.size();
       int q2=t2.size();
       vector<vector<int>> dp(q1+1,vector<int> (q2+1,-1));
       for(int i=0;i<=q1;i++){
         dp[i][0]=0;
       }
       for(int i=0;i<=q2;i++){
         dp[0][i]=0;
       }
       return solve(q1,q2,t1,t2,dp); 
    }
};