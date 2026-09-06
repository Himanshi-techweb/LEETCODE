class DSU {
    public:
    vector<int> parent,rank,component;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,1);
        component.resize(n,1);
        for(int i=0;i<n;i++)parent[i]=i;
    }
    int findparent(int node){
        if(node==parent[node])return node;
        return parent[node]=findparent(parent[node]);
    }
    void unite(int x,int y){
        int px=findparent(x);
        int py=findparent(y);
        if(px==py)return;
        if(rank[px]>rank[py]){
            parent[py]=px;
            component[px]+=component[py];
        }
        else if(rank[px]<rank[py]){
            parent[px]=py;
            component[py]+=component[px];
        }
        else {
            parent[py]=px;
            rank[px]++;
            component[px]+=component[py];
        }
    }
};
class Solution {
public:
    vector<vector<int>> rc={{0,-1},{-1,0},{0,1},{1,0}};
    int largestIsland(vector<vector<int>>& grid) {
        //total number of island first;
        int m=grid.size();
        int n=grid[0].size();
        DSU dsu(m*n);
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    //check al side
                    for(auto it:rc){
                        int nr=i+it[0];int nc=j+it[1];
                        if(nr>=0 && nr<m && nc>=0 && nc<n){
                            if(grid[nr][nc]==1){
                                int node=i*n +j;
                                int newnode=nr*n +nc;
                                dsu.unite(node,newnode);
                                
                            }
                        }
                    }
                }
                else q.push({i,j});
            }
        }
        int ans=0;
        if(q.size()==0)return n*n;
        while(!q.empty()){
            auto r=q.front().first;
            auto c=q.front().second;
            q.pop();
            unordered_set<int> unique;
            //try all direction
            for(auto it:rc){
                int nr=r+it[0];int nc=c+it[1];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1){
                    int node=nr*n +nc;
                    // int pnode=dsu.findparent(node);
                    unique.insert(dsu.findparent(node));
                }
            }
            int curr=1;
            for(auto it:unique){
                curr+=dsu.component[it];
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};