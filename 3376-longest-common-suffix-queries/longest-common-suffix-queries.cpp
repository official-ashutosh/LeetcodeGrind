class Solution {
public:
    vector<int> stringIndices(vector<string>& wc, vector<string>& wq) {
        const long long md1 = 1000000007LL;
        const long long md2 = 1000000009LL;
        const long long base1 = 26;
        const long long base2 = 29;

        int n = wc.size();
        int id = 0;
        int mn = wc[0].size();

        // key -> {index, length}
        unordered_map<long long, pair<int,int>> mp;
        mp.reserve(300000);

        auto makeKey = [&](long long h1, long long h2) -> long long {
            return (h1 << 32) ^ h2;
        };

        for (int i = 0; i < n; i++) {
            if ((int)wc[i].size() < mn) {
                mn = wc[i].size();
                id = i;
            }

            long long h1 = 0, h2 = 0;
            for (int j = (int)wc[i].size() - 1; j >= 0; j--) {
                int val = wc[i][j] - 'a' + 1;

                h1 = (h1 * base1 + val) % md1;
                h2 = (h2 * base2 + val) % md2;

                long long key = makeKey(h1, h2);

                if (!mp.count(key) ||
                    mp[key].second > (int)wc[i].size() ||
                    (mp[key].second == (int)wc[i].size() && mp[key].first > i)) {
                    mp[key] = {i, (int)wc[i].size()};
                }
            }
        }

        vector<int> ans(wq.size(), id);

        for (int i = 0; i < (int)wq.size(); i++) {
            long long h1 = 0, h2 = 0;

            for (int j = (int)wq[i].size() - 1; j >= 0; j--) {
                int val = wq[i][j] - 'a' + 1;

                h1 = (h1 * base1 + val) % md1;
                h2 = (h2 * base2 + val) % md2;

                long long key = makeKey(h1, h2);
                if (mp.count(key)) ans[i] = mp[key].first;
            }
        }

        return ans;
    }
};