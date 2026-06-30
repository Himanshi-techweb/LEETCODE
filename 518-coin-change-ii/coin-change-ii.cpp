class Solution {
public:
    vector<vector<int>> dp;
    int solve(int a,int i,vector<int> &coins){
        if(a<0)return 0;
        if(i==coins.size())return 0;
        if(a==0)return 1;
        
        if(dp[a][i]!=-1)return dp[a][i];
        int res=0;
        //take
        res+=solve(a-coins[i],i,coins);
        res+=solve(a,i+1,coins);
        return dp[a][i]=res;

    }
    int change(int amount, vector<int>& coins) {
        dp.resize(amount+10,vector<int>(coins.size()+10,-1));
        return solve(amount,0,coins);
    }
};