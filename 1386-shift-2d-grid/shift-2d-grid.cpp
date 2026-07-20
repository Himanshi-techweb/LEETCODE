class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();int n=grid[0].size();
        for(int i=0;i<k;i++){
            vector<int> arr;
            for(int i=0;i<m;i++){
                for(int j=n-1;j>=0;j--){
                    if(j==n-1)arr.push_back(grid[i][j]);
                    else{
                        grid[i][j+1]=grid[i][j];
                    }
                    

                }
            }
            grid[0][0]=arr.back();
            arr.pop_back();
            for(int i=0;i<m-1;i++){
                grid[i+1][0]=arr[i];
            }
            
        }
        return grid;
    }
};