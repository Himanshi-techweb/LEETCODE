class Solution {
public:
    vector<vector<int>> rc={{-1,0},{0,-1},{1,0},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();int n=grid[0].size();
       int fresh=0;
       vector<vector<int>> visit=grid;
       queue<pair<int,int>> q;
       int cnt=0;
       for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            visit[i][j]=0;
            if(grid[i][j]==1)fresh++;
            else if(grid[i][j]==2){
              q.push({i,j});
              visit[i][j]=1;
            }
        }
       }
       if(fresh==0)return 0;
       while(!q.empty() && fresh>0){
        int size=q.size();
        for(int i=0;i<size;i++){
           int r=q.front().first;int c=q.front().second;
         q.pop();
         bool flag=false;
         for(auto it:rc){
            int nr=it[0]+r;int nc=it[1]+c;
            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1 && visit[nr][nc]==0){
                visit[nr][nc]=1;
                q.push({nr,nc});
                flag=true;
                fresh--;
            }  
         }
        }
         cnt++;
       } 
        if(fresh>0)return-1;
        return cnt;
    }
};