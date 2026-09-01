class Solution {
public:
    int m,n;
    vector<int> r={-1,1,0,0};
    vector<int> c={0,0,1,-1};
    bool dfs(int i,int j,int pi,int pj,vector<vector<int>>&visit,vector<vector<char>> &arr){
        visit[i][j]=true;
        char actual=arr[i][j];
        for(int k=0;k<4;k++){
            int nr=i+r[k];int nc=j+c[k];
            if(nr>=0 && nr<m && nc>=0 && nc<n && arr[nr][nc]==actual){
                if(!visit[nr][nc]){
                    if(dfs(nr,nc,i,j,visit,arr))return true;
                }
                else if(nr!=pi  || nc!=pj )return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        m=grid.size();n=grid[0].size();
        vector<vector<int>> visit(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visit[i][j]){
                    if(dfs(i,j,-1,-1,visit,grid))return true;
                }
            }
        }
        return false;
        
    }
};