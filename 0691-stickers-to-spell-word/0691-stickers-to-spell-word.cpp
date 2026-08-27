class Solution {
public:

    unordered_map<string, int> dp;

    int solve(vector<vector<int>>& st, string target){
        if(target.empty()) return 0;

        if(dp.count(target)) return dp[target];

        int ans = 1e9;

        for(auto &v : st){
            string rem;
            vector<int> ct = v;

            for(char c : target){
                if(ct[c-'a'] > 0){
                    ct[c-'a']--;
                } else {
                    rem += c;
                }
            }

            if(rem == target) continue;

            ans = min(ans, 1+solve(st, rem));

        }

        return dp[target] = ans;
    }

    int minStickers(vector<string>& stickers, string target) {
        vector<vector<int>> st;

        for (auto &s : stickers){
            vector<int> cnt(26);
            for(char c : s)
                cnt[c-'a']++;
            st.push_back(cnt);
        }

        int ans = solve(st, target);
        return ans == 1e9 ? -1 : ans;
    }
};