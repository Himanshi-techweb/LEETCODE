class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int ans=0;
       vector<int> min_arr(prices.size(),-1);
    //    int temp=INT_MAX;
       int mini=prices[0];
       for(int i=1;i<prices.size();i++){
          int temp_profit=prices[i]-mini;
          ans=max(ans,temp_profit);
          mini=min(mini,prices[i]);
       }
       return ans;
    }
};