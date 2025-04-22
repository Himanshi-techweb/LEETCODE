// class Solution {
// public:
//     int idealArrays(int n, int maxValue) {
        
//     }
// };

const int MOD = 1e9 + 7;
const int MAXN = 10005;

class Solution {
public:
    int idealArrays(int n, int maxValue) {
        vector<vector<int>> dp(maxValue + 1, vector<int>(15, 0));
        vector<int> primes(maxValue + 1, 0);

        for (int i = 1; i <= maxValue; ++i) {
            dp[i][1] = 1;
        }

        for (int len = 2; len < 15; ++len) {
            for (int i = 1; i <= maxValue; ++i) {
                for (int j = 2 * i; j <= maxValue; j += i) {
                    dp[j][len] = (dp[j][len] + dp[i][len - 1]) % MOD;
                }
            }
        }

        // Precompute combinations C(n - 1, k)
        vector<vector<int>> C(n + 1, vector<int>(15, 0));
        for (int i = 0; i <= n; ++i) {
            C[i][0] = 1;
            for (int j = 1; j < 15; ++j) {
                if (j <= i)
                    C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
            }
        }

        long long ans = 0;
        for (int i = 1; i <= maxValue; ++i) {
            for (int len = 1; len < 15; ++len) {
                if (dp[i][len] > 0 && len <= n) {
                    ans = (ans + (1LL * dp[i][len] * C[n - 1][len - 1]) % MOD) % MOD;
                }
            }
        }

        return (int)ans;
    }
};