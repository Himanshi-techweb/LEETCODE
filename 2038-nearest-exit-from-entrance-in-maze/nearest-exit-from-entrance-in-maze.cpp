class Solution {
public:
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<vector<int>> rc={{-1,0},{0,-1},{1,0},{0,1}};
        queue<pair<int,int>> q;
        int m=maze.size();int n=maze[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        q.push({entrance[0],entrance[1]});
        int mini=INT_MAX;
        dist[entrance[0]][entrance[1]]=0;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            int r=front.first;int c=front.second;
            if(!(r==entrance[0] && c==entrance[1]) && (r==m-1 || r==0 || c==n-1 || c==0)){
                return dist[r][c];
            }
            for(auto it:rc){
                int nr=it[0]+r ;int nc=it[1]+c;
                if(nr>=0 && nr<m && nc>=0 && nc<n && maze[nr][nc]=='.'){
                    if(dist[nr][nc]>1+dist[r][c] ){
                        dist[nr][nc]=1+dist[r][c];
                        q.push({nr,nc});
                    }
                }
            }
        }
        
        if(mini==INT_MAX)return -1;
        return mini;
    }
};