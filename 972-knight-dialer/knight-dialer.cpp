class Solution {
public:
    vector<int> dr = {-2,-2,-1,-1,1,1,2,2};
    vector<int> dc = {-1, 1,-2, 2,-2,2,-1,1};
    const int MOD =1E9 +7;
    vector<vector<int>> number={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
    vector<vector<vector<int>>> dp;
    int solve(int i,int j,int n){
        if(n==1)return 1;
        if(dp[i][j][n]!=-1)return dp[i][j][n];
        int way=0;
        for(auto k=0;k<dr.size();k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if((nr>=0 && nr<4 && nc>=0 && nc<3) && number[nr][nc]!=-1){
                way=(way+solve(nr,nc,n-1)%MOD)%MOD;
            }
        }
        return dp[i][j][n]=way%MOD;
    }
    int knightDialer(int n) {
        int way=0;
        dp.resize(11,vector<vector<int>>(10,vector<int>(n+1,-1)));
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
               way=(way+solve(i,j,n)%MOD)%MOD;
            }
        }
        way=(way+ solve(3,1,n)%MOD)%MOD;
        return (int)way;
    }
};