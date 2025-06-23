class Solution {
public:
    int solve(int i,int j,string &x,string &y,vector<vector<int>> &dp){
       if(j<0){
           return i+1;
       }
       if(i<0){
           return j+1;
       }
       if(dp[i][j]!=-1)return dp[i][j];
       if(x[i]==y[j])return dp[i][j]=solve(i-1,j-1,x,y,dp);
        int insert=solve(i,j-1,x,y,dp);
        int replace=solve(i-1,j-1,x,y,dp);
        int erase=solve(i-1,j,x,y,dp);
        return dp[i][j]=1+min({insert,replace,erase});   
    }
    // Function to compute the edit distance between two strings
    int minDistance(string& x, string& y) {
        // code here
        int m=x.size();
        int n=y.size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solve(m-1,n-1,x,y,dp);
    }
};