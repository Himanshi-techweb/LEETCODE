class Solution {
public:
    void bfs(int r,int c, vector<vector<int>>&arr){
       int m=arr.size();
       int n=arr[0].size();  
      queue<pair<int,int>> q;
      q.push({r,c});
     
      while(!q.empty()){
        int frow=q.front().first;
        int fcol=q.front().second;
        arr[frow][fcol]=-1;
        q.pop();
        
      }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count =0;
        int fresh=0;
        vector<vector<int>> check;
        check={{0,-1},{0,1},{-1,0},{1,0}};
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(grid[i][j]==2){
                 q.push({i,j});
               }
               if(grid[i][j]==1){
                fresh++;
               }
            }
        }
        if(fresh==0)return 0;
        while(!q.empty()){
            int size=q.size();
            bool rotten=false;
            for(int i=0;i<size;i++){
                int frow=q.front().first;
                int fcol=q.front().second;
                q.pop();
                for(auto x: check){
                   int nrow=x[0]+frow;
                   int ncol=x[1]+fcol;
                   if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                        q.push({nrow,ncol});
                        grid[nrow][ncol]=2;
                        rotten=true;
                        fresh--;
                   }
                }
            }if(rotten)count++;
        }
        // if(count==0)return -1;
        if(fresh!=0)return -1;
        return count;
    }
};