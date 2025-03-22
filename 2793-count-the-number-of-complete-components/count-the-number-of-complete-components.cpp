class Solution {
public:
    vector<int> vis;
    void dfs(int node,vector<vector<int>>& adj,int &nodes,int &edges){
        nodes++;
        edges+=adj[node].size();
        vis[node]=1;
        for(auto edge:adj[node]){
            if(!vis[edge]){
                dfs(edge,adj,nodes,edges);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int node1=edges[i][0];int node2=edges[i][1];
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
        vis.resize(n,0);int k=0;
        for(int i=0;i<n;i++){
           if(!vis[i]){
            int nodes=0;int edges=0;
            dfs(i,adj,nodes,edges);
            edges=edges/2;
            if(edges==(nodes*(nodes-1)/2)){k++;}
           }
        }return k;
    }
};