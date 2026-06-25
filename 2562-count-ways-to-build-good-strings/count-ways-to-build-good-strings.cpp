class Solution {
public:
    unordered_map<int,int> dp;
    const int MOD=1e9 + 7;
    int solve(int l,int h,int z,int o,int len){
        if(len>h)return 0;
        if(dp.find(len)!=dp.end())return dp[len];
        long long ans=(len>=l);

        ans+=solve(l,h,z,o,len+z);
        ans+=solve(l,h,z,o,len+o);


        return dp[len]=ans%MOD;
        
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        string str="";
        return solve(low,high,zero,one,0);
    }
};