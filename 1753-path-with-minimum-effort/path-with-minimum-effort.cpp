class Solution {
public:
    vector<vector<int>> rc={{-1,0},{0,-1},{1,0},{0,1}};
    int minimumEffortPath(vector<vector<int>>& height) {
      priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater <pair<int,pair<int,int>>>> pq;//(dist,row,col)
      int m=height.size();
      int n=height[0].size();
      vector<vector<int>> dist(m,vector<int> (n,INT_MAX));
      pq.push({0,{0,0}});
      dist[0][0]=0;
      while(!pq.empty()){
          int effort=pq.top().first;
          int row=pq.top().second.first;
          int col=pq.top().second.second;
          pq.pop();
          for(auto it:rc){
            int nr=row+it[0];int nc=col+it[1];
            if(nr>=0 && nr<m && nc>=0 && nc<n){
                int neweffort=max(effort,abs(height[nr][nc]-height[row][col]));
                if(neweffort<dist[nr][nc]){
                    dist[nr][nc]=neweffort;
                    pq.push({neweffort,{nr,nc}});
                }
            }
          }
      }
      return dist[m-1][n-1];
    }
};