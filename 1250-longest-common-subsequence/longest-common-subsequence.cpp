class Solution {
public:
    int solve(int i1,int i2,string &t1,string &t2,vector<vector<int>> &dp){
        if(i1<0 || i2<0)return 0;
        if(dp[i1][i2]!=-1)return dp[i1][i2];
        if(t1[i1]==t2[i2]){
            return dp[i1][i2]= 1+solve(i1-1,i2-1,t1,t2,dp);
        }
        return dp[i1][i2]= max(solve(i1,i2-1,t1,t2,dp),solve(i1-1,i2,t1,t2,dp));
    }
    int longestCommonSubsequence(string t1, string t2) {
        int i1=t1.size();
        int i2=t2.size();
        vector<vector<int>> dp(i1+1,vector<int>(i2+1,0));
        for(int i=1;i<=i1;i++){
            for(int j=1;j<=i2;j++){
                 if(t1[i-1]==t2[j-1]){
                     dp[i][j]= 1+dp[i-1][j-1];
                 }
                 else dp[i][j]= max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[i1][i2];
        // return solve(i1-1,i2-1,text1,text2,dp);
    }
};