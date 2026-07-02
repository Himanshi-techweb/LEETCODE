class Solution {
public:
    // double solve(int i,int j,int amount){
    //     if(i==r && j==c)return 0;

    //     //try to check for i-1,j-1 and i-1,j amount
    //     dp[i][j]=dp[i-1]+dp[]
    // }
    double champagneTower(int poured, int r, int c) {
        if(poured==0)return 0.0;
        vector<vector<double>> dp(103,vector<double>(103,0));
        if(r==0 && c==0 && poured>=1)return 1.0;
        dp[0][0]=poured;
        for(int i=1;i<=r;i++){
            for(int j=0;j<=i;j++){
                double extra1=0;
                if(j-1>=0 && dp[i-1][j-1]>1)extra1=(dp[i-1][j-1]-1)/2.0;
                double extra2=0;
                if(dp[i-1][j]>1)extra2=(dp[i-1][j]-1)/2.0;
                dp[i][j]=extra1+extra2;
            }
        }
        return (dp[r][c]>1)?1:dp[r][c];

    }
};