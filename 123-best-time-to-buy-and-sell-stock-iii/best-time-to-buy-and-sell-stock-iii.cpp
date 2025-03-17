class Solution {
public:
    // int solve(int i,bool buy,int k,vector<int> &price,vector<vector<vector<int>>> &dp){
    //     if(i==price.size())return 0;
    //     if(k>=2)return 0;
    //     if(dp[i][buy][k]!=-1)return dp[i][buy][k];
    //     int profit=0;
    //     if(buy){
    //         profit=max(-price[i]+solve(i+1,0,k,price,dp),0+solve(i+1,1,k,price,dp));
    //     }
    //     else{
    //         profit=max(price[i]+solve(i+1,1,k+1,price,dp),0+solve(i+1,0,k,price,dp));
    //     }
    //     return dp[i][buy][k]=profit;
    // }
    int maxProfit(vector<int>& price) {
        int n=price.size();
        //vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0))); 
        //dp[n][0][0]=dp[n][0][1]=dp[n][1][0]=dp[n][1][1]=0;
        //return solve(0,1,0,prices,dp); 
        // for(int i=n-1;i>=0;i--){
        //     for(int buy=0;buy<=1;buy++){
        //         for(int k=0;k<3;k++){
        //             int profit=0;
        //             if(buy){
        //                 profit=max(-price[i]+dp[i+1][0][k],0+dp[i+1][1][k]);
        //             }
        //             else{
        //                 if(k<2)profit=max(price[i]+dp[i+1][1][k+1],0+dp[i+1][0][k]);
        //                 else profit=dp[i+1][0][k];
        //             }
        //             dp[i][buy][k]=profit; 
        //         }
        //     }
        // }
        // return dp[0][1][0];

        vector<vector<int>> next(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int k=0;k<3;k++){
                    int profit=0;
                    if(buy){
                        profit=max(-price[i]+next[0][k],0+next[1][k]);
                    }
                    else{
                        if(k<2)profit=max(price[i]+next[1][k+1],0+next[0][k]);
                        else profit=next[0][k];
                    }
                    curr[buy][k]=profit; 
                }
                next=curr;
            }
        }
        return next[1][0];
    }
};