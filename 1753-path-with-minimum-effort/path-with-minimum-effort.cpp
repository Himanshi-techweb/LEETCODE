class Solution {
public:
    int ans=INT_MAX;
    vector<vector<int>> rc={{0,-1},{-1,0},{0,1},{1,0}};
    int minimumEffortPath(vector<vector<int>>& heights) {
       int m=heights.size();int n=heights[0].size();
       if(m==1 && n==1)return 0;
       queue<pair<int,pair<int,int>>> q;
       q.push({0,{0,0}});
       vector<vector<int>> dis(m,vector<int>(n,INT_MAX));
       dis[0][0]=0;
       while(!q.empty()){
        int cnt=q.front().first;
        int r=q.front().second.first;
        int c=q.front().second.second;
        if(r==m-1 && c==n-1)ans=min(ans,cnt);
        q.pop();
        for(auto it:rc){
            int nr=r+it[0];
            int nc=c+it[1];
            if(nr>=0 & nr<m && nc>=0 && nc<n ){
                int diff=abs(heights[r][c]-heights[nr][nc]);
                int maxi=max(diff,dis[r][c]);
                if(maxi<dis[nr][nc]){
                    dis[nr][nc]=maxi;
                    q.push({dis[nr][nc],{nr,nc}});
                }
            }
        }


       } 
       return ans;
    }
};