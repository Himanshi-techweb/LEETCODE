class Solution {
public:
    void dfs(int i,vector<vector<int>> &adj,vector<int> &visit){

        for(auto it:adj[i]){
            if(!visit[it]){
                visit[it]=1;
                dfs(it,adj,visit);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
      int n= isConnected.size();
      vector<vector<int>> adj(n);
      for(int i=0;i<isConnected.size();i++){
        for(int j=0;j<isConnected.size();j++){
            if(i!=j && isConnected[i][j]==1)adj[i].push_back(j);
        }
      } 
      int cnt=0;
      vector<int> visit(n,0);
      for(int i=0;i<n;i++){
        if(!visit[i]){
            cnt++;
            visit[i]=1;dfs(i,adj,visit);
        }
      }
      return cnt;
    }
};