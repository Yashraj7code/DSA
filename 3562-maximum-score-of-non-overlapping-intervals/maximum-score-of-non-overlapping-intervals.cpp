class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // [left, right, weight, original index]
        vector<array<long long, 4>> a(n);

        for (int i = 0; i < n; ++i) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
            if (x[0] != y[0]) return x[0] < y[0];
            if (x[1] != y[1]) return x[1] < y[1];
            return x[3] < y[3];
        });

        // next[i] = first interval j such that
        // a[j][0] > a[i][1]
        vector<int> next(n);

        for (int i = 0; i < n; ++i) {
            int lo = i + 1;
            int hi = n;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                if (a[mid][0] > a[i][1])
                    hi = mid;
                else
                    lo = mid + 1;
            }

            next[i] = lo;
        }

        struct State {
            long long score = 0;
            vector<int> ids;
        };

        auto better = [](const State& x, const State& y) {
            if (x.score != y.score)
                return x.score > y.score;

            return lexicographical_compare(
                x.ids.begin(), x.ids.end(),
                y.ids.begin(), y.ids.end()
            );
        };

        // dp[i][k] = best result using intervals i..n-1,
        // choosing at most k intervals.
        vector<vector<State>> dp(n + 1, vector<State>(5));

        for (int i = n - 1; i >= 0; --i) {
            for (int k = 1; k <= 4; ++k) {

                // Don't take interval i.
                State best = dp[i + 1][k];

                // Take interval i.
                State take;
                take.score = a[i][2];
                take.ids.push_back((int)a[i][3]);

                if (k > 1) {
                    State suffix = dp[next[i]][k - 1];

                    take.score += suffix.score;

                    take.ids.insert(
                        take.ids.end(),
                        suffix.ids.begin(),
                        suffix.ids.end()
                    );
                }

                // The required answer is an array of indices
                // in increasing order.
                sort(take.ids.begin(), take.ids.end());

                if (better(take, best))
                    best = move(take);

                dp[i][k] = move(best);
            }
        }

        return dp[0][4].ids;
    }
};