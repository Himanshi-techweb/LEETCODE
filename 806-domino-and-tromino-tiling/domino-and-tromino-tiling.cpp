class Solution {
public:
    const int modulo=1e9 + 7;
    int numTilings(int n) {
       vector<int> dp(n+1,0);
       if(n>=1)dp[1]=1;
       if(n>=2)dp[2]=2;
       if(n>=3)dp[3]=5;
       for(int i=4;i<=n;i++){
        dp[i]=(2*dp[i-1]%modulo +dp[i-3]%modulo)%modulo;
       } 
       return dp[n];
    }
};