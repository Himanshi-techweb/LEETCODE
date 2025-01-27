class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int ans=0;
       vector<int> min_arr(prices.size(),-1);
       int temp=INT_MAX;
       for(int i=0;i<prices.size();i++){
        min_arr[i]=min(temp,prices[i]);
        temp=min_arr[i];
       }
       for(int i=prices.size()-1;i>0;i--){
        ans=max(ans,prices[i]-min_arr[i]);
       }
       return ans;
    }
};