class DSU {
    public:
    vector<int> parent,rank,component;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,1);
        component.resize(n,1);
        for(int i=0;i<n;i++)parent[i]=i;
    }
    int findparent(int node){
        if(node==parent[node])return node;
        return parent[node]=findparent(parent[node]);
    }
    void unite(int x,int y){
        int px=findparent(x);
        int py=findparent(y);
        if(px==py)return;
        if(rank[px]>rank[py]){
            parent[py]=px;
            component[px]+=component[py];
        }
        else if(rank[px]<rank[py]){
            parent[px]=py;
            component[py]+=component[px];
        }
        else {
            parent[py]=px;
            rank[px]++;
            component[px]+=component[py];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DSU dsu(stones.size() );
        int n=stones.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    dsu.unite(i,j);
                }
            }
        }
        int ans=0;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(dsu.findparent(i));
        }

        for(auto it:st){
            ans+=(dsu.component[it]-1);
        }
        return ans;
    }
};