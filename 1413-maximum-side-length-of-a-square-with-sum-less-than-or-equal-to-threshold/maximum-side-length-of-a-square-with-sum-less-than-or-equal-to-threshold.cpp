class Solution {
public:
    // int maxSideLength(vector<vector<int>>& mat, int threshold) {
    //     vector<vector<int>> rowsum;
    //     vector<vector<int>> colsum;
    // }
    int maxSideLength(vector<vector<int>>& grid, int threshold)  {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> rowsum(m, vector<int>(n));
        vector<vector<int>> colsum(m, vector<int>(n));
        // if(m==1 && n==1 && grid[m-1][n-1]<=threshold)return 1;

        // Row prefix sum
        for (int i = 0; i < m; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
                rowsum[i][j] = sum;
            }
        }

        // Column prefix sum (FIXED)
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int i = 0; i < m; i++) {
                sum += grid[i][j];
                colsum[i][j] = sum;
            }
        }

        int size = 0;

        // Check all submatrices
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int maxSize = min(m - i, n - j);

                for (int k = 0; k < maxSize; k++) {  // k+1 is square size
                    int new_i = i + k;
                    int new_j = j + k;

                    bool ok = true;
                    int sum=0;
                    // Check rows
                    for (int r = i; r <= new_i ; r++) {
                        sum+=(rowsum[r][new_j] - (j > 0 ? rowsum[r][j - 1] : 0));
                        // int s = rowsum[r][new_j] - (j > 0 ? rowsum[r][j - 1] : 0);
                        if(sum >threshold){
                           ok=false;
                           break;
                        }
                    }

                    if(!ok)break;
                    else size = max(size, k + 1);
                }
            }
        }

        return size;
    }

};