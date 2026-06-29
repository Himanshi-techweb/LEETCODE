class Solution {
public:
    vector<pair<int,int>> arr={{100,0},{75,25},{50,50},{25,75}};
    vector<vector<double>> dp;
    double solve(int a,int b){
        if(a<=0 && b<=0)return 0.5;
        if(a<=0)return 1.0;
        if(b<=0)return 0.0;
        if(dp[a][b]!=-1)return dp[a][b];
        double x=0.0;
        for(auto it:arr){
            x+=solve(a-it.first,b-it.second);
        }
        return dp[a][b]=0.25 * (double)x;
        
    }
    double soupServings(int n) {
        if(n>7000)return 1;
        dp.resize(n+1,vector<double>(n+1,-1));
        return solve(n,n);
    }
};