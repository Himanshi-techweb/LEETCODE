class Solution {
public:
    long long countInterestingSubarrays(vector<int>& arr, int modulo, int k) {
        unordered_map<int, long long> freq;
        freq[0] = 1;  // base case: prefix mod 0
        long long ans = 0;
        int prefixMod = 0;

        for (int i = 0; i < arr.size(); ++i) {
            // Update prefixMod: count of elements where arr[i] % modulo == k
            if (arr[i] % modulo == k) {
                prefixMod = (prefixMod + 1) % modulo;
            }

            // Find the target mod we're looking for
            int target = (prefixMod - k + modulo) % modulo;

            // Add to answer the number of times this target occurred
            ans += freq[target];

            // Update frequency map
            freq[prefixMod]++;
        }

        return ans;
    }
};