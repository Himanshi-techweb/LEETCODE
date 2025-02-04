class Solution {
    void bfs(int sr,int sc,vector<vector<int>> &arr){
        int m=arr.size();
        int n=arr[0].size();
        int x=arr[sr][sc];
        arr[sr][sc]=-1;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=-1;i<=1;i++){
                int nrow=row+i;
                int ncol=col;
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && arr[nrow][ncol]==x && arr[nrow][ncol]!=-1){
                    bfs(nrow,ncol,arr);
                }
            }    
            for(int i=-1;i<=1;i++){
                int nrow=row;
                int ncol=col+i;
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && arr[nrow][ncol]==x && arr[nrow][ncol]!=-1){
                    bfs(nrow,ncol,arr);
                }
            }    
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& arr, int sr, int sc, int color) {
        bfs(sr,sc,arr);
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[0].size();j++){
                if(arr[i][j]==-1){
                    arr[i][j]=color;
                }
            }
        }
        return arr;
    }
};