class Solution {
public:
    int maxProfit(vector<int>& price, int fee) {
        int n=price.size();
        vector<int> next(2,0);
        vector<int> curr(2,0);
        next[0]=next[1]=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
               int profit=0;
                if(buy){
                   profit=max(-price[i]+next[0],0+next[1]);
                }
                else{
                   profit=max(price[i]+next[1]-fee,0+next[0]);
                }
                curr[buy]=profit;
            }
            next=curr;
        }
        return next[1];
    }
};