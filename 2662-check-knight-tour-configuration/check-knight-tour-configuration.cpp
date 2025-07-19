class Solution {
public:
    vector<pair<int,int>> rc={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    bool solve(int i,int j,int cnt,vector<vector<int>> &arr,int n){
        if(cnt==n*n-1)return true;
        for(auto it:rc){
            int nr=i+it.first;
            int nc=j+it.second;
            if(nr>=0 && nr<n && nc>=0 && nc<n && arr[nr][nc]==cnt+1){
                if(solve(nr,nc,cnt+1,arr,n))return true;
            }
        }
        return false;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=grid.size();int x=0;int y=0;
        if(grid[0][0]!=0)return false;
       return solve(0,0,0,grid,n);
    }
};