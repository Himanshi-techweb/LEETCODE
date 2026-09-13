class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
       int n = img1.size();
        vector<pair<int, int>> ones1, ones2;

        // Collect coordinates of all 1s
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) ones1.push_back({r, c});
                if (img2[r][c] == 1) ones2.push_back({r, c});
            }
        }

        // Map vector diff -> count of overlaps
        map<pair<int, int>, int> count;
        int max_overlap = 0;

        for (auto& [r1, c1] : ones1) {
            for (auto& [r2, c2] : ones2) {
                pair<int, int> shift = {r2 - r1, c2 - c1};
                count[shift]++;
                max_overlap = max(max_overlap, count[shift]);
            }
        }

        return max_overlap; 
    }
};