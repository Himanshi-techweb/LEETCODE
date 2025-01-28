class Solution {
public:
int solve(int index,int buy,vector<int> &arr,vector<vector<vector<int>>> &dp,int x){
        if(x==0)return 0;
        if(index==arr.size()){
            return 0;
        }
        if(dp[index][buy][x]!=-1)return dp[index][buy][x];
        long long profit=0;
        if(buy){
             profit=max(-arr[index]+solve(index+1,0,arr,dp,x),0+solve(index+1,1,arr,dp,x));
        }
        else{
             profit=max(arr[index]+solve(index+1,1,arr,dp,x-1),0+solve(index+1,0,arr,dp,x));
        }
        return dp[index][buy][x]=profit;
    }

    // int maxProfit(vector<int>& prices) {
    //     int x=2;
    //     // vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(x+1,-1)));
    //     vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(x+1,0)));

    //     // return solve(0,1,prices,dp,x);
    //     int n=prices.size();
    //    for(int index=n-1;index>=0;index--){
    //     for(int buy=0;buy<=1;buy++){
    //         for(int tran=1;tran<=x;tran++){
    //             long long profit=0;
    //             if(buy){
    //                profit=max(-prices[index]+dp[index+1][0][tran],0+dp[index+1][1][tran]);
    //             }
    //             else{
    //                profit=max(prices[index]+dp[index+1][1][tran-1],0+dp[index+1][0][tran]);
    //             }
    //             dp[index][buy][tran]=profit; 
    //         }
    //     }
    //    }return dp[0][1][x];

    // }








    int maxProfit(vector<int>& prices) {
        int x=2;
        // vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(x+1,-1)));
        vector<vector<int>> curr(2,vector<int>(x+1,0));
        vector<vector<int>> next(2,vector<int>(x+1,0));
        // return solve(0,1,prices,dp,x);
        int n=prices.size();
       for(int index=n-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
            for(int tran=1;tran<=x;tran++){
                if(buy){
                  curr[buy][tran]=max(-prices[index]+next[0][tran],0+next[1][tran]);
                }
                else{
                   curr[buy][tran]=max(prices[index]+next[1][tran-1],0+next[0][tran]);
                }
                
            }
        }next=curr;
        
       }return next[1][x];

    }
};