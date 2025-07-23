class Solution {
public:
    void dfs(int i,int parent,vector<vector<int>> &adj,vector<int> &visit,int &cnt){
        cnt++;
        for(auto it:adj[i]){
            if(!visit[it]){
                visit[it]=1;
                dfs(it,i,adj,visit,cnt);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visit(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
          if(!visit[i]){
            int cnt=0;
            visit[i]=1;
            dfs(i,-1,adj,visit,cnt);
            ans.push_back(cnt);
          } 
        }
        long long x=0;
        vector<long long> prefixsum(ans.size(),0);
        prefixsum[ans.size()-1]=ans[ans.size()-1];
        for(int i=ans.size()-2;i>=0;i--){
            prefixsum[i]=prefixsum[i+1]+ans[i];
        }
        for(int i=0;i<ans.size()-1;i++){
            x=x+(ans[i]*prefixsum[i+1]);
        }
        return x;
    }
};