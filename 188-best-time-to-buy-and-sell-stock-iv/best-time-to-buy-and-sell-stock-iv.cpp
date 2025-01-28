class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int x=k;
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