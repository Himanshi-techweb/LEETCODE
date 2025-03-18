class Solution {
public:
    int solve(int i,int prev,vector<int> & arr,vector<vector<int> >&dp){
        if(i==arr.size())return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        //take
        int take=0;
        if(prev==-1 || arr[i]>arr[prev]){
            take=1+solve(i+1,i,arr,dp);
        }
        //not take
        int nottake=solve(i+1,prev,arr,dp);
        return dp[i][prev+1]=max(take,nottake);
    }//taking 0 ensure it always return non negative LIS and for base case it handle empty sequence
    //can take INT_MIN for take but make sure take=max(take,1+solve(i+1,i,arr,dp)) otherwise it will lead to take as INT_MIN in some case and if not take is 0 then dp[i][prev+1]=INT_MIN;and here it dp[i][prev+1]=0 if max(take,nottake )only if not change take=max(take,1+solve(i+1,i,arr,dp)) but LIS cannot be less than 1;
    int lengthOfLIS(vector<int>& num) {
        int n=num.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        return solve(0,-1,num,dp);
    }
};