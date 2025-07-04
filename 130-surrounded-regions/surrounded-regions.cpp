class Solution {
public:
    vector<vector<int>> rc={{-1,0},{0,-1},{0,1},{1,0}};
    void dfs(int i,int j,int m,int n,vector<vector<char>>&arr){
        //visit[i][j]=1;
        arr[i][j]='*';
        for(auto it:rc){
            int nr=i+it[0];
            int nc=j+it[1];
            if(nr>=0 && nr<m && nc>=0 && nc<n &&  arr[nr][nc]=='O'){
                dfs(nr,nc,m,n,arr);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        // vector<vector<int>> visit(m,vector<int> (n,0));
        for(int i=0;i<m;i++){
            if(board[i][0]=='O')dfs(i,0,m,n,board);
            if(board[i][n-1]=='O')dfs(i,n-1,m,n,board);
        }
        for(int i=0;i<n;i++){
            if(board[0][i]=='O')dfs(0,i,m,n,board);
            if(board[m-1][i]=='O')dfs(m-1,i,m,n,board);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='*')board[i][j]='O';
                else if(board[i][j]=='O')board[i][j]='X';
            }
        }
    }
};