class Solution {
public:
    vector<vector<int>> rc={{2, 1}, {1, 2}, {-1, 2}, {-2, 1},{-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    
    double solve(int row,int col,int k,int n,vector<vector<vector<double>>> &dp){
       if(row<0 || row>=n || col<0 || col>=n){
        return 0;
       }
       if(dp[row][col][k]!=-1)return dp[row][col][k];
       if(k==0){
         return 1;
       }
       double prob=0.0;
       for(auto it:rc){
        int nr=row+it[0];int nc=col+it[1];
        prob+=(0.125 *solve(nr,nc,k-1,n,dp));
       }
       return dp[row][col][k]=prob;
    }
    double knightProbability(int n, int k, int row, int column) {
    //    total=0;there=0;
    //    vector<vector<int>> chess(n,vector<int> (n,1));
    vector<vector<vector<double>>> dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
       return solve(row,column,k,n,dp);
    }
};