class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> rowsum(m, vector<int>(n));
        vector<vector<int>> colsum(m, vector<int>(n));

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

        int size = 1;

        // Check all submatrices
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int maxSize = min(m - i, n - j);

                for (int k = 1; k < maxSize; k++) {  // k+1 is square size
                    int new_i = i + k;
                    int new_j = j + k;

                    int target = rowsum[i][new_j] - (j > 0 ? rowsum[i][j - 1] : 0);
                    bool ok = true;

                    // Check rows
                    for (int r = i; r <= new_i && ok; r++) {
                        int s = rowsum[r][new_j] - (j > 0 ? rowsum[r][j - 1] : 0);
                        if (s != target) ok = false;
                    }

                    // Check columns
                    for (int c = j; c <= new_j && ok; c++) {
                        int s = colsum[new_i][c] - (i > 0 ? colsum[i - 1][c] : 0);
                        if (s != target) ok = false;
                    }

                    // Main diagonal
                    int diag1 = 0;
                    for (int d = 0; d <= k; d++) {
                        diag1 += grid[i + d][j + d];
                    }
                    if (diag1 != target) ok = false;

                    // Anti-diagonal
                    int diag2 = 0;
                    for (int d = 0; d <= k; d++) {
                        diag2 += grid[i + d][new_j - d];
                    }
                    if (diag2 != target) ok = false;

                    if (ok) size = max(size, k + 1);
                }
            }
        }

        return size;
    }
};
