class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // Path compression
    }

    void unite(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) swap(rootX, rootY);
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
};


class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
      int m = grid.size(), n = grid[0].size();
        int totalCells = m * n;
        vector<pair<int, int>> cells; // Store {value, index}

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cells.push_back({grid[i][j], i * n + j});
            }
        }

        sort(cells.begin(), cells.end());  // Sort by value

        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());  // Sort queries

        vector<int> result(queries.size(), 0);
        DSU dsu(totalCells);
        vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        vector<bool> visited(totalCells, false);
        
        int idx = 0, count = 0;

        for (auto [query, qIndex] : sortedQueries) {
            while (idx < totalCells && cells[idx].first < query) {
                int pos = cells[idx].second;
                int r = pos / n, c = pos % n;
                visited[pos] = true;
                count++;

                for (auto d : directions) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && visited[nr * n + nc]) {
                        dsu.unite(pos, nr * n + nc);
                    }
                }

                idx++;
            }

            if (visited[0]) result[qIndex] = dsu.size[dsu.find(0)];
        }

        return result;
      
    }
};