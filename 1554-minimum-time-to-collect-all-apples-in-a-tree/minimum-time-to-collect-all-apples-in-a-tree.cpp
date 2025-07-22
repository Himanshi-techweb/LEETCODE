class Solution {
public:
    int dfs(vector<vector<int>> &adj,vector<bool> &hasapple,int curr,int parent){
        int time=0;
        for(auto child:adj[curr]){
            if(child==parent)continue;
            int time_takenbychild=dfs(adj,hasapple,child,curr);
            if(time_takenbychild>0 || hasapple[child]){
               time+=(time_takenbychild+2);
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return dfs(adj,hasApple,0,-1);
    }
};