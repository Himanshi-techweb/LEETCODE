class Solution {
public:
    vector<vector<int>> rc={{-1,0},{0,-1},{1,0},{0,1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();int n=image[0].size();
        int orig=image[sr][sc];
        if(orig==color)return image;
        queue<pair<int,int>> q;
        vector<vector<int>> visit=image;
        q.push({sr,sc});
        visit[sr][sc]=color;
        while(!q.empty()){
           int r=q.front().first;int c=q.front().second;
           q.pop();
           for(auto it:rc){
              int nr=it[0]+r;int nc=it[1]+c;
              if(nr>=0 && nr<m && nc>=0 && nc<n && image[nr][nc]==orig && visit[nr][nc]!=color){
                  q.push({nr,nc});
                  visit[nr][nc]=color;
              }
           }
        }
        return visit;
    }
};