class Solution {
public:
    vector<vector<int>> dp;
    const int MOD=1e9 + 7;
    int solve(int unique,int song,int n,int goal,int k){
        if(song==goal)return unique==n;
        if(dp[unique][song]!=-1)return dp[unique][song];
        long long res=0;
        res+=(1LL*(n-unique)*solve(unique+1,song+1,n,goal,k)%MOD)%MOD;
        if(unique>k)res+=(1LL*(unique-k)*solve(unique,song+1,n,goal,k)%MOD)%MOD;
        return dp[unique][song]=res%MOD;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        dp.resize(101,vector<int>(101,-1));
        return solve(0,0,n,goal,k);
    }
};