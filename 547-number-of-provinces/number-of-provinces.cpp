class Solution {
public:
    void dfs(int i,vector<vector<int>> &arr,vector<int> &visit){
        visit[i]=1;
        for(auto it:arr[i]){
            if(!visit[it])dfs(it,arr,visit);
        }
    }
    int findCircleNum(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<vector<int>> adj(n);
        for(auto i=0;i<n;i++){
            for(int j=0;j<n;j++){
            if(arr[i][j]==1 && i!=j)  { 
            adj[i].push_back(j);
            adj[j].push_back(i);
            }
        }
        }
        vector<int> visit(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visit[i]){
                dfs(i,adj,visit);
                cnt++;
            }
        }
        return cnt;

    }
};