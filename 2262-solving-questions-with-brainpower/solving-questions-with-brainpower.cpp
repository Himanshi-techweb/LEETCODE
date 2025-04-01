class Solution {
public:
    long long solve(int i,vector<long long>&dp,vector<vector<int>> &arr){
        int n=arr.size();
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        long long include=arr[i][0]+solve(arr[i][1]+i+1,dp,arr);
        long long exclude=0+solve(i+1,dp,arr);
        return dp[i]=max(include,exclude);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
       vector<long long > dp(n,0);
    //    //vector<vector<long long>> 
    //    return solve(0,dp,questions);
    for(int i=n-1;i>=0;i--){
        long long x=questions[i][0];
        int nexti=questions[i][1]+i+1;
        long long include=x+(nexti<n?dp[nexti]:0);
        long long exclude=(i+1<n?dp[i+1]:0);
        dp[i]=max(include,exclude);
    }
    return dp[0];
    }
};