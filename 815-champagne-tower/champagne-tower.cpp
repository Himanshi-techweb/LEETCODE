class Solution {
public:
    double solve(int pour,int i,int j,vector<vector<double>> &dp){
        if(i==0 && j==0 )return pour;
        if(i<0 || j<0 || i<j)return 0.0;
        if(dp[i][j]!=-1)return dp[i][j];
        double left=(solve(pour,i-1,j-1,dp)-1)/2.0;
        if(left<0)left=0;
        double right=(solve(pour,i-1,j,dp)-1)/2.0;
        if(right<0)right=0;
        return dp[i][j]= left+right;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(100+1,vector<double> (100+1,-1));
        if(poured==0.0)return 0.0;
        // if(poured>1e8)return 1.0;
        if(query_row==0 && query_glass==0)return 1.0;
        double ans= solve(poured,query_row,query_glass,dp);
        if(ans>1.0)return 1.0;
        return ans;
    }
};