class Solution {
public:
     vector<vector<int>> ans;
    void dfs(int node,vector<vector<int>>& adj,vector<int> &curr,int n,vector<int> &visit){
        if(node==n-1){
            ans.push_back(curr);
            return;
        }
        for(auto it:adj[node]){
            if(!visit[it]){
               curr.push_back(it);
               visit[it]=1;
               dfs(it,adj,curr,n,visit); 
               curr.pop_back();
               visit[it]=0;
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
       vector<int>curr={};
       curr.push_back(0);
       int n=adj.size();
       vector<int> visit(n,0);
       visit[0]=1;
       dfs(0,adj,curr,n,visit);
       return ans; 
    }
};