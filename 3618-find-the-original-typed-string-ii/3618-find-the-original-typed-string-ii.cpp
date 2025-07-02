class Solution {
public:
    static const int MOD = 1000000007;

    int possibleStringCount(string word, int k) {
        int n = word.size();
        // build run-lengths
        vector<int> v;
        int cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (word[i] == word[i - 1]) {
                ++cnt;
            } else {
                v.push_back(cnt);
                cnt = 1;
            }
        }
        v.push_back(cnt);

        int m = v.size();
        // total number of all xi-sequences = product v[i]
        long long total = 1;
        for (int len : v) {
            total = total * len % MOD;
        }

        // minimal possible sum of picks is m (xi>=1)
        if (m >= k) {
            // every sequence has sum >= m >= k
            return int(total);
        }

        // badge: we need to subtract sequences whose sum < k,
        // i.e. rem in [m .. k-1]

        // We'll do a backward DP over only the last `use_runs = min(m, k)` runs,
        // because for id < m - k, minimal sum exceeds k-1 and contributes zero.
        int start = max(0, m - k);
        int use_runs = m - start;  // <= k

        // dp_next[r] = number of ways for runs[id+1..m-1] to sum to r
        vector<int> dp_next(k, 0), dp_cur(k);
        dp_next[0] = 1;  // at id = m, only rem=0 is valid

        // iterate id = m-1 down to start
        for (int ri = 1; ri <= use_runs; ++ri) {
            int id = m - ri;
            int runs_left = ri;  // runs from id..m-1
            // build prefix sums of dp_next
            vector<long long> pref(k);
            pref[0] = dp_next[0];
            for (int r = 1; r < k; ++r) {
                pref[r] = (pref[r - 1] + dp_next[r]) % MOD;
            }
            // compute dp_cur for this id
            fill(dp_cur.begin(), dp_cur.end(), 0);
            for (int rem = 0; rem < k; ++rem) {
                // need rem >= runs_left (since xi>=1 per run)
                if (rem < runs_left) continue;
                // xi ∈ [1 .. min(v[id], rem-(runs_left-1))]
                int max_x = min(v[id], rem - (runs_left - 1));
                // dp_cur[rem] = sum_{x=1..max_x} dp_next[rem-x]
                // = pref[rem-1] - pref[rem-1-max_x]
                long long sum = pref[rem - 1];
                int tail = rem - 1 - max_x;
                if (tail >= 0) sum = (sum - pref[tail] + MOD) % MOD;
                dp_cur[rem] = int(sum);
            }
            dp_next.swap(dp_cur);
        }

        // now dp_next[r] = dp[start][r]; since start==0 when m<k, this is dp[0]
        // bad = sum rem=m..k-1 dp[0][rem]
        long long bad = 0;
        for (int rem = m; rem < k; ++rem) {
            bad = (bad + dp_next[rem]) % MOD;
        }

        long long ans = (total - bad) % MOD;
        if (ans < 0) ans += MOD;
        return int(ans);
    }
};
