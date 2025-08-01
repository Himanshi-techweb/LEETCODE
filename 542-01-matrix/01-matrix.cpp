class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       int m=mat.size();int n=mat[0].size();
       vector<vector<int>> rc={{0,-1},{0,1},{1,0},{-1,0}};
       vector<vector<int>> dist(m,vector<int> (n,INT_MAX));
       queue<pair<pair<int,int>,int>> q;
       for(int  i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==0){
               dist[i][j]=0;
               q.push({{i,j},0});
            }
        }
       }
       while(!q.empty()){
         auto front=q.front();q.pop();
         int r=front.first.first;int c=front.first.second;
         int d=front.second;
         for(auto it:rc){
            int nr=it[0]+r;int nc=it[1]+c;
            if(nr>=0 && nr<m && nc>=0 && nc<n && mat[nr][nc]==1 && dist[nr][nc]>1+dist[r][c]){
                dist[nr][nc]=1+dist[r][c];
                q.push({{nr,nc},dist[nr][nc]});
            }
         }
       }
       return dist; 
    }
};