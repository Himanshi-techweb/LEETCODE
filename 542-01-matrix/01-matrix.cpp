class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       queue<pair<pair<int,int>,int>> q;
       vector<vector<int>> visit(mat.size(),vector<int> (mat[0].size(),0));
       vector<vector<int>> ans=mat;
       vector<vector<int>> rc={{0,-1},{-1,0},{0,1},{1,0}};
       for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            if(mat[i][j]==0){
                q.push({{i,j},0});
                visit[i][j]=1;
            }
        }
       }
       while(!q.empty()){
          int row=q.front().first.first;
          int col=q.front().first.second;
          int wt=q.front().second;
          q.pop();
          for(auto it:rc){
            int nr=row+it[0];
            int nc=col+it[1];
            if(nr>=0 && nr<mat.size()  && nc>=0 && nc<mat[0].size()  && visit[nr][nc]==0 && mat[nr][nc]==1){
                q.push({{nr,nc},wt+1});
                visit[nr][nc]=1;
                ans[nr][nc]=wt+1;
            }
          }
       }
       return ans;
    }
};