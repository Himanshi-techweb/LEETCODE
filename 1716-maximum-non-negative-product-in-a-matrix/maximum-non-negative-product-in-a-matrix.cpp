class Solution {
public:
    vector<vector<int>> rc={{0,1},{1,0}};
    const int MOD=1e9 +7;
    int m;int n;vector<vector<pair<long long,long long>>> dp;
    int ans=INT_MIN;
    pair<long long,long long> solve(int i,int j,vector<vector<int>> &grid){
    //    if(i>=m || j>=n)return INT_MIN;
       if(i==m-1 && j==n-1){
        return {grid[i][j],grid[i][j]};
       }
       if(dp[i][j].first!=LLONG_MIN)return dp[i][j];
       long long maxi=LLONG_MIN;long long mini=LLONG_MAX;
       for(auto it:rc){
        int nr=i+it[0];int nc=j+it[1];
        if(nr<m && nr>=0 && nc<n && nc>=0){
            auto [mx,mn]=solve(nr,nc,grid);
            if(mx==LLONG_MIN || mn==LLONG_MAX)continue;
            long long a=grid[i][j]*mx;
            long long b=grid[i][j]*mn;

            maxi=max(maxi,max(a,b));
            mini=min(mini,min(a,b));


            // int check=grid[i][j]*solve(nr,nc,grid);
            // ans=max(ans,check);
        }
       }
       return dp[i][j]={maxi  ,mini };

        
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        dp.assign(m,vector<pair<long long ,long long>>(n,{LLONG_MIN,LLONG_MIN}));
        pair<long long,long long>  ans=solve(0,0,grid);
        if( ans.first<0 )return -1;
        return ans.first%MOD;
        // return (ans<0)?-1:ans;
    }
};