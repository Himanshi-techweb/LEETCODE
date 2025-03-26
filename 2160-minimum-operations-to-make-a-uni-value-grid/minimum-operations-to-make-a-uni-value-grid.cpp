class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> values;
        int m = grid.size(), n = grid[0].size();

        // Flatten the grid and check feasibility
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                values.push_back(grid[i][j]);
            }
        }

        // Check if making the grid uni-value is possible
        int remainder = values[0] % x;
        for (int num : values) {
            if (num % x != remainder) return -1;
        }

        // Find the median
        sort(values.begin(), values.end());
        int median = values[values.size() / 2];

        // Compute total number of operations
        int operations = 0;
        for (int num : values) {
            operations += abs(num - median) / x;
        }

        return operations;
    }
};