class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int q=prices.size();
        // vector<int> before(q,0);
        // vector<int> after(q,0);
        // after[q-1]=prices[q-1];
        // before[0]=prices[0];
        // for(int i=1;i<q;i++){
        //     before[i]=min(prices[i],before[i-1]);
        // }
        // for(int i=q-2;i>=0;i--){
        //     after[i]=max(prices[i],after[i+1]);
        // }
        int profit=0;
        int mini=prices[0];
        for(int i=1;i<q;i++){
           profit=max(profit,prices[i]-mini);
           mini=min(mini,prices[i]);
        }return profit;
    }
};