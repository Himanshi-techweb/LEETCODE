class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count =0;
        int fresh=0;
        vector<pair<int,int>> check;
        check={{0,-1},{0,1},{-1,0},{1,0}};
        queue<pair<int,int>> q;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
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
                   int nrow=x.first+frow;
                   int ncol=x.second+fcol;
                   if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && grid[nrow][ncol]==1){
                        q.push({nrow,ncol});
                        grid[nrow][ncol]=2;
                        rotten=true;
                        fresh--;
                   }
                }
            }if(rotten)count++;
        }
        if(fresh!=0)return -1;
        return count;
    }
};