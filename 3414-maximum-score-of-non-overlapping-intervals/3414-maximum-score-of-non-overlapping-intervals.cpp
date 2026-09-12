class Solution {
    struct State {
        long long score = 0;
        vector<int> ids;
    };

    // Return the better state:
    // 1. larger score
    // 2. lexicographically smaller index array on ties
    State better(const State& a, const State& b) {
        if (a.score != b.score)
            return a.score > b.score ? a : b;
        return a.ids < b.ids ? a : b;
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {left, right, weight, original index}
        vector<array<long long, 4>> a;
        a.reserve(n);

        for (int i = 0; i < n; ++i) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by right endpoint.
        sort(a.begin(), a.end(),
             [](const auto& x, const auto& y) {
                 if (x[1] != y[1]) return x[1] < y[1];
                 return x[0] < y[0];
             });

        vector<long long> ends(n);
        for (int i = 0; i < n; ++i)
            ends[i] = a[i][1];

        // prev[i] = last interval j < i with a[j].right < a[i].left
        vector<int> prev(n);

        for (int i = 0; i < n; ++i) {
            long long l = a[i][0];

            // first right endpoint >= l
            int j = lower_bound(ends.begin(), ends.begin() + i, l)
                    - ends.begin();

            prev[i] = j - 1;
        }

        // dp[i][k]:
        // best answer using first i intervals and at most k intervals.
        vector<array<State, 5>> dp(n + 1);

        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k <= 4; ++k) {
                // Don't choose interval i-1
                State skip = dp[i - 1][k];

                // Choose interval i-1
                int p = prev[i - 1];

                State take = dp[p + 1][k - 1];
                take.score += a[i - 1][2];

                take.ids.push_back((int)a[i - 1][3]);
                sort(take.ids.begin(), take.ids.end());

                dp[i][k] = better(skip, take);
            }
        }

        return dp[n][4].ids;
    }
};