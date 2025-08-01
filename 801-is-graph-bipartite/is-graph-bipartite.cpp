class Solution {
public:
    bool dfs(int i,int parent,vector<int> &color,vector<vector<int>> &graph,vector<int> &visit){
        for(auto it:graph[i]){
            if(!visit[it]){
                visit[it]=1;
                color[it]=!color[i];
                if(!dfs(it,i,color,graph,visit))return false;
            }
            else if(it!=parent && color[i]==color[it])return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visit(graph.size(),0);
        vector<int> color(graph.size());
        for(int i=0;i<graph.size();i++){
            if(!visit[i]){
                visit[i]=1;
                if(!dfs(i,-1,color,graph,visit))return false;
            }
        } 
        return true;
    }
};