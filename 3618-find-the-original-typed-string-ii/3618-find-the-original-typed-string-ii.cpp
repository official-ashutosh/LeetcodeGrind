class Solution {
public:
    static const int MOD = 1000000007;

    int possibleStringCount(string word, int k) {
        int n = word.size();
        // build run-lengths
        v.clear();
        int cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (word[i] == word[i - 1]) ++cnt;
            else { v.push_back(cnt); cnt = 1; }
        }
        v.push_back(cnt);

        m = v.size();

        // total number of all xi-sequences = product v[i]
        total = 1;
        for (int len : v) total = total * len % MOD;

        // minimum sum xi = m (one per run)
        if (m >= k) 
            return int(total);

        // suffix sums of available characters
        suff.assign(m, 0);
        suff[m - 1] = v[m - 1];
        for (int i = m - 2; i >= 0; --i) 
            suff[i] = suff[i + 1] + v[i];

        this->k = k;
        start = max(0, m - k);
        use_runs = m - start;

        // dp[ri][rem], ri=0..use_runs, rem=0..k-1
        dp.assign(use_runs + 1, vector<int>(k, 0));

        // fill recursively
        solve(0);
        solve(use_runs);

        // count bad sums rem in [m..k-1]
        long long bad = 0;
        for (int rem = m; rem < k; ++rem) {
            bad = (bad + dp[use_runs][rem]) % MOD;
        }

        long long ans = (total - bad) % MOD;
        return int(ans < 0 ? ans + MOD : ans);
    }

private:
    int m, k, start, use_runs;
    long long total;
    vector<int> v, suff;
    vector<vector<int>> dp;

    // recursively ensure dp[ri] is filled; base case ri=0
    void solve(int ri) {
        if (ri == 0) {
            dp[0][0] = 1;
            return;
        }
        // ensure previous level is ready
        solve(ri - 1);

        int id = m - ri;
        int runs_left = ri;
        // build prefix sums of dp[ri-1]
        static vector<long long> pref;
        pref.assign(k, 0);
        pref[0] = dp[ri - 1][0];
        for (int r = 1; r < k; ++r) {
            pref[r] = (pref[r - 1] + dp[ri - 1][r]) % MOD;
        }
        // compute dp[ri][rem]
        for (int rem = 0; rem < k; ++rem) {
            if (rem < runs_left) {
                dp[ri][rem] = 0;
            } else {
                int max_x = min(v[id], rem - (runs_left - 1));
                long long sum = (rem > 0 ? pref[rem - 1] : 0);
                int cut = rem - 1 - max_x;
                if (cut >= 0) sum = (sum - pref[cut] + MOD) % MOD;
                dp[ri][rem] = int(sum);
            }
        }
    }
};
