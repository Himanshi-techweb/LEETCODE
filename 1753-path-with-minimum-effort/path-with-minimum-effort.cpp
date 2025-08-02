class Solution {
public:
    vector<vector<int>> rc={{0,-1},{-1,0},{0,1},{1,0}};
    int minimumEffortPath(vector<vector<int>>& heights) {
      int m=heights.size();int n=heights[0].size();
      priority_queue<vector<int>,vector<vector<int>> ,greater<vector<int>> >q;
      q.push({0,0,0});//height,row,col
      int mini=INT_MAX;
      vector<vector<int>> dist(m,vector<int> (n,INT_MAX));
      dist[0][0]=0;
      while(!q.empty()){
        auto front=q.top();q.pop();
        int effort=front[0];int r=front[1];int c=front[2];
        if(r==m-1 && c==n-1)return effort;
        for(auto it:rc){
            int nr=it[0]+r;int nc=it[1]+c;
            if(nr>=0 && nr<m && nc>=0 && nc<n ){
                int neweffort=max(abs(heights[nr][nc]-heights[r][c]),effort);
                if(dist[nr][nc]>neweffort){
                  dist[nr][nc]=neweffort;
                  q.push({neweffort,nr,nc});
                }
            }
        }
      }
      return mini; 
    }
};