class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int it=x;
        int ti=x+k-1;
        // cout<<it<< " "<<ti<<endl;
        int col_it=y;
        while(it<ti){
            //swap between row
            col_it=y;
            while(col_it<y+k){
                swap(grid[it][col_it],grid[ti][col_it]);

                col_it++;
            }
            // cout<<it<<" "<<ti<<endl;
            it++;
            ti--;
            
        }
        return grid;

    }
};