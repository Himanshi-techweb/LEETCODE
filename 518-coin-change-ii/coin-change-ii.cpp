class Solution {
public:
    int solve(int i,int tar,vector<int> &arr,vector<vector<int>> &dp){
        if(i==0){
            if(tar%arr[0]==0)return 1;
            else return 0;
        }
        if(dp[i][tar]!=-1)return dp[i][tar];
        int take=0;
        if(arr[i]<=tar)take=solve(i,tar-arr[i],arr,dp);
        int nottake=solve(i-1,tar,arr,dp);
        return dp[i][tar]=take+nottake;
    }  
    int change( int amount,vector<int>& arr) {
        int m=arr.size();
        vector<vector<int>> dp(m+1,vector<int> (amount+1,-1));
       return solve(m-1,amount,arr,dp); 
    }
};