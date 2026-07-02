class Solution {
public:
    vector<vector<int>> dp;
    vector<int> rc={-1,0,1};
    const int MOD=1E9 +7;
    int solve(int i,int len,int steps){
        if(steps==0){
            return (i==0);
        }
        if(dp[i][steps]!=-1)return dp[i][steps];
        int way=0;
        //try each 3 direction but consider that i-1 is greater than -1 
        for(auto it:rc){
            int new_i=it+i;
            if(new_i>=0 && new_i<len){
                way=(way+(solve(new_i,len,steps-1))%MOD)%MOD;
            }
        }
        return dp[i][steps]=way%MOD;
    }
    int numWays(int steps, int arrLen) {
        dp.resize(min(steps,arrLen)+1,vector<int>(steps+1,-1));
        return solve(0,arrLen,steps);
    }
};