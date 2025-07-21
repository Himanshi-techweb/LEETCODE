class Solution {
public:
    void dfs(int i,int n,vector<int> &visit,vector<vector<int>>& adj){
        for(auto it:adj[i]){
            if(!visit[it]){
                visit[it]=1;
                dfs(it,n,visit,adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>visit(n,0);int cnt=0;//count disconnected component teher is graph
        vector<vector<int> >adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int total_wire=connections.size();
        for(int i=0;i<n;i++){
            if(!visit[i]){
                visit[i]=1;
                cnt++;
                dfs(i,n,visit,adj); 
            }
        }
        //count how many component not connected to any other computer 
        return (total_wire>=n-1)?cnt-1:-1;
        
    }
};