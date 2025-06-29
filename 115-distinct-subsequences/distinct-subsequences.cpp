class Solution {
public:
    int solve(int i,int j,string x,string y,vector<vector<int>> &dp){
        if(j<0)return 1;
        if(i<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        //match
        int result=0;
        if(x[i]==y[j]){
            result+=solve(i-1,j,x,y,dp)+solve(i-1,j-1,x,y,dp);
        }
        else{
            result+=solve(i-1,j,x,y,dp);
        }
        return dp[i][j]=result;
    }
    int numDistinct(string x, string y) {
        vector<vector<int>> dp(x.size(),vector<int>(y.size(),-1));
        return solve(x.size()-1,y.size()-1,x,y,dp);
    }
};