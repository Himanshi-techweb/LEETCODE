class Solution {
public:
    int count;
    const int MOD=1e9 +7;
    vector<vector<int>> dp;
    int solve(int n,int tar){
        if(tar==0){
            if(n==0)return 1;
            return 0;
        }
        if(dp[n][tar]!=-1)return dp[n][tar];
        int way=0;
        for(int k=1;k<=count;k++){
            if(tar-k>=0 && n-1>=0)way=(way+solve(n-1,tar-k)%MOD)%MOD;
        }
        return dp[n][tar]=way%MOD;
    }
    int numRollsToTarget(int n, int k, int target) {
       count=k; 
       dp.resize(n+10,vector<int>(target+11,-1));
       return solve(n,target);
    }
};