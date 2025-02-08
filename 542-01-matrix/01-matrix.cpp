class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       int m=mat.size();
       int n=mat[0].size();
       vector<vector<int>> ans(m,vector<int> (n,-1));
       queue<pair<int,int>> q;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==0){
                q.push({i,j});
                ans[i][j]=0;
            }
        }
       }
    //    vector<pair<int,int>> check;
    vector<int> rowcheck={0,-1,0,1};
    vector<int> colcheck={-1,0,1,0};
    //    check={{0,-1},{-1,0},{0,1},{1,0}};
       while(!q.empty()){
          int row=q.front().first;
          int col=q.front().second;
          q.pop();
          for(int i=0;i<4;i++){
             int nrow=row+rowcheck[i];
             int ncol=col+colcheck[i];
             if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && ans[nrow][ncol]==-1){
                ans[nrow][ncol]=1+ans[row][col];
                q.push({nrow,ncol});
             }
          }
       } 
       return ans;
    }
};