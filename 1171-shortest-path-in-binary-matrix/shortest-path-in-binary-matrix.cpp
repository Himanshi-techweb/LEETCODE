class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      int n=grid.size();
      if(grid[0][0]!=0)return -1;
     if(n==1 && grid[0][0]==0)return 1;
      pair<int,int> source={0,0};
      pair<int,int> destination={n-1,n-1};
        if(grid[source.first][source.second]==1)return -1;
        if(grid[destination.first][destination.second]==1)return -1;
        vector<vector<int>>check(n,vector<int> (n,INT_MAX));
        vector<pair<int,int>> temp;
        temp={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{1,1},{-1,1},{1,-1}};
        queue<pair<int,pair<int,int>>>q;
        check[source.first][source.second]=1;
        q.push({1,{source.first,source.second}});
        while(!q.empty()){
            int dist=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(int i=0;i<temp.size();i++){
                int temp_row=row+temp[i].first;
                int temp_col=col+temp[i].second;
                if(temp_row>=0 && temp_row<n && temp_col>=0 && temp_col<n && grid[temp_row][temp_col]==0){
                    if(dist+1<check[temp_row][temp_col]){
                        check[temp_row][temp_col]=dist+1;
                        q.push({dist+1,{temp_row,temp_col}});
                        if(temp_row==destination.first && temp_col==destination.second){
                            return check[temp_row][temp_col];
                        }
                    }
                }
            }
        }
        return -1;   
    }
};