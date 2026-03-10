class Solution {
public:
    const int MOD =1'000'000'007;
    int numberOfStableArrays(int zero, int one, int limit) {
        

        vector<vector<vector<int>>> dp(one+1,vector<vector<int>>(zero+1,vector<int>(2,0)));
        //base case if start 1 
        for(int i=0;i<=min(limit,one);i++){
            dp[i][0][1]=1;
        }
        //base case if start 0
        for(int j=0;j<=min(limit,zero);j++){
            dp[0][j][0]=1;
        }


        //loop
        for(int i=1;i<=one;i++){
            for(int j=1;j<=zero;j++){
                
                dp[i][j][0]=(dp[i][j-1][1]+dp[i][j-1][0])%MOD;
                if(j-1-limit>=0){
                    dp[i][j][0]=(dp[i][j][0]-dp[i][j-1-limit][1]+MOD)%MOD;
                }
                dp[i][j][1]=(dp[i-1][j][0]+dp[i-1][j][1])%MOD;
                if(i-1-limit>=0){
                    dp[i][j][1]=(dp[i][j][1]-dp[i-1-limit][j][0]+MOD)%MOD;
                }
                // dp[i][j][1]=(dp[i][j-1][1]+dp[i][j-1][0]-dp[i][j-1-limit][0])%MOD;
                // dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j][1]-dp[i-limit-1][j][1])%MOD;
            }
        }
        return (dp[one][zero][0]+dp[one][zero][1])%MOD;
    }
    
};