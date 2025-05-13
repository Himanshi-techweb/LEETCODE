class Solution {
public:
    // int lengthAfterTransformations(string s, int t) {
        
    // }
    const int MOD = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        vector<long long> freq(26, 0); // freq[i] = number of characters with code 'a' + i
        for (char c : s) {
            freq[c - 'a']++;
        }

        for (int step = 0; step < t; ++step) {
            vector<long long> nextFreq(26, 0);
            for (int i = 0; i < 25; ++i) {
                nextFreq[i + 1] = (nextFreq[i + 1] + freq[i]) % MOD;
            }
            // 'z' becomes "ab"
            nextFreq[0] = (nextFreq[0] + freq[25]) % MOD; // 'a'
            nextFreq[1] = (nextFreq[1] + freq[25]) % MOD; // 'b'
            freq = nextFreq;
        }

        long long result = 0;
        for (int i = 0; i < 26; ++i) {
            result = (result + freq[i]) % MOD;
        }
        return result;
    }
};