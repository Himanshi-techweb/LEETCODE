class Solution {
public:
    // int solve(int id_n,int k,int target){
    //     if(target!=0 && id_n==0)return 0;
    //     if(id_n!=0 && target==0)return 0;
    //     if(target<0)return 0;
    //     int ans=0;
    //     for(int i=1;i<=k;i++){
    //         ans=ans+solve(id_n-1,k,target-i);
    //     }   
    //     return ans;
    // }
    int solve(int id_n,int k,int target,vector<vector<int>>&dp){
        if(target!=0 && id_n==0)return 0;
        if(id_n!=0 && target==0)return 0;
        if(target<0)return 0;
        if(target==0 && id_n==0)return 1;
        if(dp[id_n][target]!=-1)return dp[id_n][target];
        int ans=0;
        for(int i=1;i<=k;i++){
            ans=(ans+solve(id_n-1,k,target-i,dp))%1000000007;
        }   
        return dp[id_n][target]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
       return solve(n,k,target,dp); 
    }
};