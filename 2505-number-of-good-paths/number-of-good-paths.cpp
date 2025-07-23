class Solution {
public:
    vector<int> rank;vector<int> parent;
    int findparent(int node){
        if(node==parent[node])return node;
        return parent[node]=findparent(parent[node]);
    }
    void dsu(int u,int v){
        int parent_u=findparent(u);
        int parent_v=findparent(v);
        if(parent_u==parent_v)return;
        if(rank[parent_u]<rank[parent_v]){
            parent[parent_u]=parent_v;
        }
        else if(rank[parent_u]>rank[parent_v])parent[parent_v]=parent_u;
        else{
            parent[parent_u]=parent_v;
            rank[parent_v]++;
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        rank.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++)parent[i]=i;

        unordered_map<int,vector<int>> adj;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        map<int,vector<int>> val_tonode;
        for(int i=0;i<vals.size();i++){
            val_tonode[vals[i]].push_back(i);
        }
        int ans=n;
        //vector of active member
        vector<bool> active(n,false);
        for(auto it:val_tonode){
            for(auto u:it.second){
                for(auto v:adj[u]){
                    if(active[v]){
                        dsu(u,v);
                    }
                }
                active[u]=true;
            }
            vector<int> tmhare_parent;
            for(auto u:it.second){
                int parent_kaun=findparent(u);
                tmhare_parent.push_back(parent_kaun);
            }
            
            sort(tmhare_parent.begin(),tmhare_parent.end());
            for(int i=0;i<tmhare_parent.size();i++){
                int curr_parent=tmhare_parent[i];
                long long cnt=0;
                while(i<tmhare_parent.size() && tmhare_parent[i]==curr_parent){
                    cnt++;i++;
                }
                i--;
                ans+=((cnt*(cnt-1))/2);
            }
        }
        return ans;
    }
};