class Solution {
public:
    int mini=INT_MAX;
    void dfs(int node,vector<vector<pair<int,int>>> &adj,vector<int> &visit){
        for(auto it:adj[node]){
            mini=min(mini,it.second);
            if(!visit[it.first]){
                visit[it.first]=1;
                dfs(it.first,adj,visit);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int> visit(n+1,0);
        visit[1]=1;
        
        dfs(1,adj,visit);
        
        return mini;
        
    }
};