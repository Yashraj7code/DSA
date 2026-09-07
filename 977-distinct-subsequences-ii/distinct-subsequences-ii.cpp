class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        vector<long long> last(26, 0);

        long long dp = 0;

        for (char c : s) {
            int x = c - 'a';

            long long newDp = (2 * dp + 1 - last[x] + MOD) % MOD;

            last[x] = (dp + 1) % MOD;
            dp = newDp;
        }

        return dp;
    }
};