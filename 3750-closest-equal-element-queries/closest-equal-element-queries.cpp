class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> valToIndices;
        
        // Step 1: Map values to their sorted indices
        for (int i = 0; i < n; ++i) {
            valToIndices[nums[i]].push_back(i);
        }
        
        vector<int> results;
        for (int qIdx : queries) {
            int targetVal = nums[qIdx];
            const vector<int>& indices = valToIndices[targetVal];
            
            if (indices.size() <= 1) {
                results.push_back(-1);
                continue;
            }
            
            // Step 2: Binary search for neighbors
            auto it = lower_bound(indices.begin(), indices.end(), qIdx);
            int pos = distance(indices.begin(), it);
            
            int minDist = n; // Initialize with max possible circular distance
            
            // Check neighbor to the right
            int rightIdx = indices[(pos + 1) % indices.size()];
            int d1 = abs(qIdx - rightIdx);
            minDist = min({minDist, d1, n - d1});
            
            // Check neighbor to the left
            int leftIdx = indices[(pos - 1 + indices.size()) % indices.size()];
            int d2 = abs(qIdx - leftIdx);
            minDist = min({minDist, d2, n - d2});
            
            results.push_back(minDist);
        }
        
        return results;
    }
};