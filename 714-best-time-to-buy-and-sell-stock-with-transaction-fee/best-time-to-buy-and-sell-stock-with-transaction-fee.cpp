class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,bool buy,vector<int> &arr,int f){
        if(i>=arr.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int ans=0;
        //if buy that buy=1;
        if(buy==1){
            //then must sell
            ans=max(solve(i+1,buy,arr,f),-arr[i]+solve(i+1,!buy,arr,f));
        }
        else{
            ans=max(solve(i+1,buy,arr,f),arr[i]+solve(i+1,!buy,arr,f)-f);
        }
        return dp[i][buy]=ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        dp.resize(prices.size()+1,vector<int> (2,-1));
        return solve(0,1,prices,fee);
    }
};