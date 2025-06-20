
class Solution {
public:
    vector<vector<int>> rc={{-1,0},{0,-1},{0,1},{1,0}};
    void dfs(int i,int j,int m,int n,vector<vector<int>>&arr){
        arr[i][j]=-1;
        for(auto it:rc){
            int nr=i+it[0];
            int nc=j+it[1];
            if(nr>=0 && nr<m && nc>=0 && nc<n &&  arr[nr][nc]==1){
                dfs(nr,nc,m,n,arr);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            if(board[i][0]==1)dfs(i,0,m,n,board);
            if(board[i][n-1]==1)dfs(i,n-1,m,n,board);
        }
        for(int i=0;i<n;i++){
            if(board[0][i]==1)dfs(0,i,m,n,board);
            if(board[m-1][i]==1)dfs(m-1,i,m,n,board);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==-1)board[i][j]=0;
                else if(board[i][j]==1)cnt++;
            }
        }
        return cnt;
    }
};