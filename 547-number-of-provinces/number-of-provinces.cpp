class Solution {
public:
    void dfs(vector<vector<int>>& arr,int i,vector<int> &vis){
           vis[i]=1;
           for(int j=0;j<arr.size();j++){
            if(arr[i][j]==1 && vis[j]==0){
                dfs(arr,j,vis);
            }
           }
    }
    int findCircleNum(vector<vector<int>>& arr) {
        int n=arr.size();
       int count=0;
       vector<int> vis(arr.size(),0);
       for(int i=0;i<n;i++){
         if(!vis[i]){
            count++;
            dfs(arr,i,vis);
         }  
       }
       return count; 
    }
};