// class Solution {
// public:
//     int (vector<vector<>>& grid) {
        
//     }
// };
class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& arr,vector<vector<int>> &vis){
     vis[row][col]=1;
      queue<pair<int,int>> q;
      q.push({row,col});
      int m=arr.size();
      int n=arr[0].size();
      while(!q.empty()){
        int nrow=q.front().first;
        int ncol=q.front().second;
        q.pop();
        for(int i=-1;i<=1;i++){
            // for(int j=-1;j<=1;j++){
                int nrow2=nrow+i;
                int ncol2=ncol;
                if(nrow2>=0 && nrow2<m && ncol2>=0 && ncol2<n && !vis[nrow2][ncol2] && arr[nrow2][ncol2]=='1'){
                    vis[nrow2][ncol2]=1;
                    q.push({nrow2,ncol2});
                }
            // }
        }
        for(int i=-1;i<=1;i++){
            // for(int j=-1;j<=1;j++){
                int nrow2=nrow;
                int ncol2=ncol+i;
                if(nrow2>=0 && nrow2<m && ncol2>=0 && ncol2<n && !vis[nrow2][ncol2] && arr[nrow2][ncol2]=='1'){
                    vis[nrow2][ncol2]=1;
                    q.push({nrow2,ncol2});
                }
            // }
        }
      }
    }
    int numIslands(vector<vector<char>>& arr) {
        int m=arr.size();
        int n=arr[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && arr[i][j]=='1'){
                    count++;
                    dfs(i,j,arr,vis);
                }
            }
        }
        
       return count; 
    }
};