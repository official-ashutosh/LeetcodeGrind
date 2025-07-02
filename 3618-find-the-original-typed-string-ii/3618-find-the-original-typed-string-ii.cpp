class Solution {
public:
    static const int MOD = 1000000007;

    int possibleStringCount(string word, int k) {
        int n = word.size();
        // build run-lengths
        vector<int> v;
        int cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (word[i] == word[i-1]) ++cnt;
            else { v.push_back(cnt); cnt = 1; }
        }
        v.push_back(cnt);

        int m = v.size();
        // total number of all xi-sequences = product v[i]
        long long total = 1;
        for (int len : v) total = total * len % MOD;
        // minimum picks is m (xi>=1)
        if (m >= k) return int(total);

        // suffix sums to check bounds
        vector<int> suff(m);
        suff[m-1] = v[m-1];
        for (int i = m-2; i >= 0; --i) suff[i] = suff[i+1] + v[i];

        // we only need to consider the last 'use_runs' runs,
        // since picking 1 from each of more than k runs already exceeds k-1.
        int start = max(0, m - k);
        int use_runs = m - start;

        // dp[id][rem] for id in [start..m], rem in [0..k-1]
        vector<vector<int>> dp(use_runs+1, vector<int>(k, 0));

        // recursive fill from id = start to m
        function<void(int)> solve = [&](int ri) {
            // ri = 0..use_runs; corresponds to actual id = m - ri
            if (ri == 0) {
                // base case: id = m
                dp[0][0] = 1;
                return;
            }
            // first solve for shorter suffix
            solve(ri-1);
            int id = m - ri;
            // build prefix sums of dp[ri-1]
            vector<int> &prev = dp[ri-1], &cur = dp[ri];
            vector<long long> pref(k);
            pref[0] = prev[0];
            for (int r = 1; r < k; ++r) pref[r] = (pref[r-1] + prev[r]) % MOD;
            // compute dp[ri][rem]
            int runs_left = ri;
            for (int rem = 0; rem < k; ++rem) {
                if (rem < runs_left) {
                    cur[rem] = 0;
                } else {
                    int max_x = min(v[id], rem - (runs_left - 1));
                    // sum prev[rem-x] for x=1..max_x → pref[rem-1] - pref[rem-1-max_x]
                    long long sum = pref[rem-1];
                    int cut = rem - 1 - max_x;
                    if (cut >= 0) sum = (sum - pref[cut] + MOD) % MOD;
                    cur[rem] = int(sum);
                }
            }
        };

        solve(use_runs);
        // dp[use_runs] is dp[start]
        long long bad = 0;
        for (int rem = m; rem < k; ++rem) {
            bad = (bad + dp[use_runs][rem]) % MOD;
        }
        long long ans = (total - bad) % MOD;
        if (ans < 0) ans += MOD;
        return int(ans);
    }
};
