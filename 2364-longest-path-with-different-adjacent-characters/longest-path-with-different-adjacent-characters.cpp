class Solution {
public:
     int maxi=INT_MIN;
    int dfs(int node,int parent,vector<vector<int>> &adj,string &s){
        int longest=0;int slongest=0;
        for(auto it:adj[node]){
           if(it==parent)continue;
           int childpath=dfs(it,node,adj,s);
           if(s[node]!=s[it]){
            if(childpath>longest){
                slongest=longest;
                longest=childpath;
            }
            else if(childpath<=longest && childpath>slongest){
                slongest=childpath;
            }
           }
        }
        maxi=max(maxi,1+longest+slongest);
        return 1+max(longest,slongest);
    }
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            adj[i].push_back(parent[i]);
            if(parent[i]!=-1)adj[parent[i]].push_back(i);
        }
        dfs(0,-1,adj,s);
        return maxi;
    }
};