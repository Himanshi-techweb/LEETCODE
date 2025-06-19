class Disjoint{
  public:
  vector<int> size,parent;
  Disjoint(int n){
      size.resize(n+1,1);
      parent.resize(n+1);
      for(int i=0;i<=n;i++){
          parent[i]=i;
      }
  }
  int findUParent(int node){
      if(node==parent[node])return node;
      return parent[node]=findUParent(parent[node]);
  }
  void Unionbysize(int u,int v){
      int ulp_u=findUParent(u);
      int ulp_v=findUParent(v);
      if(ulp_u==ulp_v)return;
      if(size[ulp_u]<size[ulp_v]){
          parent[ulp_u]=ulp_v;
          size[ulp_v]+=size[ulp_u];
      }
      else{
          parent[ulp_v]=ulp_u;
          size[ulp_u]+=size[ulp_v];
      }
  }
};
class Solution {
public:
    int makeConnected(int V, vector<vector<int>>& edge) {
      Disjoint check(V);
      for(int i=0;i<edge.size();i++){
                    if(check.findUParent(edge[i][0])!=check.findUParent(edge[i][1])){
                       check.Unionbysize(edge[i][0],edge[i][1]);
                    } 
        }
       unordered_set<int> q;
       for(int i=0;i<V;i++){
          q.insert(check.findUParent(i)); 
       }
    //    int total=V;int disconnect=q.size()-1;int network=total-disconnect+1;int require=disconnect-1;int remain=edge.size()-1;
       if(edge.size()<V-1)return -1;  
       return q.size()-1;
    }
};