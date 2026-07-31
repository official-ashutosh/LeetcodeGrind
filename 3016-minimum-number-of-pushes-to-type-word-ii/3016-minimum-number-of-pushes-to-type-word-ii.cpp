class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26, 0);

        for(auto c : word) {
            mp[c-'a']++;
        }

        sort(mp.rbegin(), mp.rend());

        int ans = 0;

        for(int i = 0; i < 26; ++i) {
            if (mp[i] == 0) break;
            ans += (i / 8 + 1) * mp[i];
        }

        return ans;
    }
};