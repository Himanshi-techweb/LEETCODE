class Solution {
public:
    vector<vector<string>> ans;
    bool check(int i,int j,vector<string>&arr,int n){
       for(int k=0;k<n;k++){
        if(arr[i][k]=='Q')return false;
       } 
       int row=i;int col=j;
       row--;col--;
       while(row>=0 && col>=0){
        if(arr[row][col]=='Q')return false;
        row--;col--;
       }
       i++;j--;
       while(i<n && j>=0){
        if(arr[i][j]=='Q')return false;
        i++;j--; 
       }
       return true;
    }
    void solve(int col,vector<string>&board,int n){
        if(col==n){
           ans.push_back(board);return;
        }
        for(int i=0;i<n;i++){
            if(check(i,col,board,n)){
                board[i][col]='Q';
                solve(col+1,board,n);
                board[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
       vector<string> board(n);
       string s(n,'.');
       for(int i=0;i<n;i++){
        board[i]=s;
       } 
       solve(0,board,n);
       return ans;
    }
};