
class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
       int m=board.size();
       int n=board[0].size();
       queue<pair<int,int>> q;
        //top row
        for(int j=0;j<n;j++){
            if(board[0][j]==1){
                q.push({0,j});
                 board[0][j]=-1;
            }
        }//bottom
        for(int j=0;j<n;j++){
            if(board[m-1][j]==1){
                q.push({m-1,j});
                board[m-1][j]=-1;
            }
        }//left
        for(int i=0;i<m;i++){
            if(board[i][0]==1){
                q.push({i,0});
                board[i][0]=-1;
            }}
        for(int i=0;i<m;i++){//right
            if(board[i][n-1]==1){
                q.push({i,n-1});
                board[i][n-1]=-1;
            }}
        vector<pair<int,int>> check;
        check={{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(auto x: check){
                int nrow=row+x.first;
                int ncol=col+x.second;
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && board[nrow][ncol]==1){
                    q.push({nrow,ncol});
                    board[nrow][ncol]=-1;}}}
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==-1){
                    board[i][j]=1;
                }
                else if(board[i][j]==1){
                    board[i][j]=0;
                    count++;
                }} } return count;} 
};