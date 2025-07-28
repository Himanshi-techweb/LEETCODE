class Solution {
public:
    long long solve(int i,vector<vector<int>> &arr,vector<long long> &dp){
        if(i>=arr.size() )return 0;
        if(dp[i]!=-1)return dp[i];
        long long take=arr[i][0]+solve(i+arr[i][1]+1,arr,dp);
        long long nottake=solve(i+1,arr,dp);
        return dp[i] =max(take,nottake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(),-1);
       return solve(0,questions,dp); 

    }
};