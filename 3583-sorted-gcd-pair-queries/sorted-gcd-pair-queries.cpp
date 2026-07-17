class Solution {
public:

    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        // freq[x] = frequency of value x
        vector<long long> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        // exact[g] = number of pairs having gcd exactly g
        vector<long long> exact(mx + 1, 0);

        // Count pairs divisible by g
        for (int g = 1; g <= mx; g++) {

            long long cnt = 0;

            for (int j = g; j <= mx; j += g)
                cnt += freq[j];

            exact[g] = cnt * (cnt - 1) / 2;
        }

        // Inclusion-Exclusion
        for (int g = mx; g >= 1; g--) {
            for (int j = 2 * g; j <= mx; j += g)
                exact[g] -= exact[j];
        }

        // Prefix count
        vector<long long> prefix(mx + 1, 0);
        for (int g = 1; g <= mx; g++)
            prefix[g] = prefix[g - 1] + exact[g];

        // Answer queries
        vector<int> ans;

        for (long long k : queries) {

            // kth pair (0-indexed)
            int g = lower_bound(prefix.begin(), prefix.end(), k + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;

    }
};