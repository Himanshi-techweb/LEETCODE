class Solution {
public:
    const int MOD=1e9 + 7;
    long long solve(int countsong,int countunique,int n,int goal,int k,vector<vector<int>> &dp){
        if(countsong==goal){
            return countunique==n;
        }
        if(dp[countsong][countunique]!=-1)return dp[countsong][countunique];
        long long result=0;
        if(countunique<n){
           result+=(n-countunique)*solve(countsong+1,countunique+1,n,goal,k,dp);
        }
        if(countunique>k)result+=(countunique-k)*solve(countsong+1,countunique,n,goal,k,dp);
        return dp[countsong][countunique]=result%MOD;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>> dp(goal+1,vector<int> (n+1,-1));
        return solve(0,0,n,goal,k,dp);
    }
};