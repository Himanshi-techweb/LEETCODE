class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> great(prices.size());
        great[prices.size()-1]=prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;i--){
            great[i]=max(prices[i],great[i+1]);
        }
        int ans=0;
        for(int i=0;i<prices.size()-1;i++){
            ans=max(ans,great[i+1]-prices[i]);
        }
        return ans;
    }
};