class Solution {
public:
    int dp[101][202];
    const int MOD=1e9 +7;
    int solve(int i,int fi,int fuel,vector<int> &arr,int n){
        if(fuel<0)return 0;
        if(dp[i][fuel]!=-1)return dp[i][fuel];
        int count=(i==fi)?1:0;
        for(int j=0;j<n;j++){
            if(j==i)continue;
            int cost=abs(arr[i]-arr[j]);
            if(fuel>=cost){
                count=(count+solve(j,fi,fuel-cost,arr,n)%MOD)%MOD;
            }
        }
        return dp[i][fuel]=count;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n=locations.size();
        memset(dp,-1,sizeof(dp));
        return solve(start,finish,fuel,locations,n);
    }
};
