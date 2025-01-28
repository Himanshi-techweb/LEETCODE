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

    int maxProfit(vector<int>& prices) {
        int x=2;
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(x+1,-1)));
        return solve(0,1,prices,dp,x);
      
    }
};