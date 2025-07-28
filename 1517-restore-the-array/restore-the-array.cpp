class Solution {
public:
    const int MOD=1e9+7;
    int solve(int start,string &s,int k,vector<int> &dp){
        if(start>=s.size())return 1;
        if(s[start]=='0')return 0;
        if(dp[start]!=-1)return dp[start];
        long long ans=0;
        long long num=0;
        for(int end=start;end<s.size();end++){
            num=num*10+(s[end]-'0');
            if(num>k)break;
            ans=(ans+solve(end+1,s,k,dp)%MOD)%MOD;
        }
        return dp[start]=ans%MOD;
       } 
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.length()+1,-1);
       return solve(0,s,k,dp);
    }
};