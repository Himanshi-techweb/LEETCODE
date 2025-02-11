class Solution {
public:
//anyone part of cycle is not safe node any node which lead to cycle is not safe node
    bool dfscycle(int i,vector<vector<int>> &arr,vector<int> &vis,vector<int> &pathvis,vector<int> &check){
        pathvis[i]=1;
        vis[i]=1;
        check[i]=0;
        for(auto it:arr[i]){
            if(!vis[it]){
                if(dfscycle(it,arr,vis,pathvis,check)==true){
                    check[i]=0;
                    return true;
                }
            }
            else if(pathvis[it]){
                check[i]=0;
                return true;
            }
        }
        check[i]=1;
        pathvis[i]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      int n=graph.size();
       vector<int> vis(n,0);
       vector<int> pathvis(n,0);
       vector<int> check(n,0);
       for(int i=0;i<n;i++){
        if(!vis[i]){
            dfscycle(i,graph,vis,pathvis,check);
        }
       }
       vector<int> ans;
       for(int i=0;i<n;i++){
        if(check[i]==1){
            ans.push_back(i);
        }
       } 
       return ans; 
    }
};