class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
       vector<vector<int>> visit(m,vector<int> (n,0));
       int fresh=0;
       queue<pair<int,int>>q;
       vector<vector<int>> rc={{-1,0},{0,-1},{1,0},{0,1}};
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(grid[i][j]==2){
            q.push({i,j});
            visit[i][j]=1;
          } 
          else if(grid[i][j]==1)fresh++; 
        }
       }int cnt=0;
       while(!q.empty() && fresh>0){
        int size=q.size();
        for(int i=0;i<size;i++){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(auto it:rc){
            int nr=row+it[0];
            int nc=col+it[1];
            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1){
                q.push({nr,nc});
                visit[nr][nc]=1;
                grid[nr][nc]=2;
                fresh--;
            }
        }
        }
        cnt++;
       }
       if(fresh>0)return -1;
       return cnt; 
    }
};