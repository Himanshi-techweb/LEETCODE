class Solution {
public:
     int ans=0;
    void dfs(int node,int parent,vector<vector<pair<int,int>>>&adj,vector<int> &visit){
        for(auto it:adj[node]){
            if(it.first!=parent){
               if(it.second==1){
                ans=ans+1;
               }
               dfs(it.first,node,adj,visit);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:connections){
            adj[it[0]].push_back({it[1],1});
            adj[it[1]].push_back({it[0],0});
        }
         vector<int> visit(n,0);
         visit[0]=1;
         dfs(0,-1,adj,visit);
         return ans;
    }
};