class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> f;

        for (auto x : text) {
            f[x]++;
        }

        int ans = INT_MAX;

        ans = min(ans, f['b']);
        ans = min(ans, f['a']);
        ans = min(ans, f['l'] / 2);
        ans = min(ans, f['o'] / 2);
        ans = min(ans, f['n']);

        return ans;
    }
};