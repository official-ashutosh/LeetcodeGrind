class Solution {
public:
    unordered_map<string, int> dp;

    int solve(vector<vector<int>>& stickers, string target) {
        if (target.empty()) return 0;

        if (dp.count(target))
            return dp[target];

        int ans = 1e9;

        for (auto &st : stickers) {
            vector<int> cnt = st;
            string rem;

            for (char c : target) {
                if (cnt[c - 'a'])
                    cnt[c - 'a']--;
                else
                    rem += c;
            }

            // Sticker didn't help
            if (rem == target)
                continue;

            int x = solve(stickers, rem);

            if (x != 1e9)
                ans = min(ans, x + 1);
        }

        return dp[target] = ans;
    }

    int minStickers(vector<string>& stickers, string target) {
        vector<vector<int>> v;

        for (auto &s : stickers) {
            vector<int> cnt(26, 0);
            for (char c : s)
                cnt[c - 'a']++;
            v.push_back(cnt);
        }

        int ans = solve(v, target);

        return ans == 1e9 ? -1 : ans;
    }
};