class Solution {
public:
    const int MOD=1e9 +7;
    int solve(int low,int high,int zero,int one,int len,vector<int> &dp){
        if(len>high)return 0;
        if(dp[len]!=-1)return dp[len];
        bool addone=false;
        if(len>=low && len<=high )addone=true;
        //append 0
        
        int take_0=solve(low,high,zero,one,len+zero,dp)%MOD;
        int take_1=solve(low,high,zero,one,len+one,dp)%MOD;
        return dp[len]=(addone+take_0+take_1)%MOD;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,-1);
        return solve(low,high,zero,one,0,dp);
    }
};