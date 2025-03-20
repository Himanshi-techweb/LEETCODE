class dsu{
    public:
    vector<int> parent;
    vector<int> rank;
    dsu(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
        int findparent(int node){
            if(node==parent[node]){
                return node;
            }
            parent[node]=findparent(parent[node]);
            return parent[node];
        }
        void unionrank(int node1,int node2){
        int parent1=findparent(node1);
        int parent2=findparent(node2);
        if(parent1==parent2)return;
        if(rank[parent1]<rank[parent2]){
            parent[parent1]=parent2;
        }
        else if(rank[parent2]<rank[parent1]){
            parent[parent2]=parent1;
        }
        else{
            parent[parent2]=parent1;
            rank[parent1]++;
        }}
};
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
       dsu check(n);
       vector<int> ans(n,INT_MAX);
       vector<int> submit(query.size());
       for(auto edge:edges){
         check.unionrank(edge[0],edge[1]);
       }

       for(auto edge:edges){
         int parent1=check.findparent(edge[0]);
         ans[parent1]=(ans[parent1]&edge[2]);
       } 
       for(int i=0;i<query.size();i++){
        int parent1=check.findparent(query[i][0]);
        int parent2=check.findparent(query[i][1]);
        if(parent1!=parent2){
          submit[i]=-1;
        }
        else{
          submit[i]=ans[parent1];
        }
       }return submit;
    }
};