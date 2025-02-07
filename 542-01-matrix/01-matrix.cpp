class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      int m=mat.size();
      int n=mat[0].size();
      queue<pair<int,int>> q;

    //   vector<vector<int>> vis(m,vector<int> (n,0));
      vector<vector<int>> ans(m,vector<int> (n,-1));
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==0){
               q.push({i,j});
               ans[i][j]=0;
            }
        }
      }
      vector<int> row={-1,0,1,0};
      vector<int> col={0,1,0,-1}; 
      while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        // int x=q.front().second;
        q.pop();
        // ans[r][c]=x;
        for(int i=0;i<4;i++){
            int nc=c+col[i];
            int nr=r+row[i];
            if(nc>=0 && nc<n && nr>=0 && nr<m && ans[nr][nc]==-1){
                ans[nr][nc]=ans[r][c]+1;
                q.push({nr,nc});
            }
        }
      }
      return ans;
    }
};