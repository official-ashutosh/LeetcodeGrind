class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> mp(26, 0);

        int l = 0, r = 0, ans = 1, ct = 0;
        int n = s.size();

        while(r < n){
            mp[s[r]-'A']++;
            ct = max(ct, mp[s[r]-'A']);

            while((r-l+1)-ct > k){
                mp[s[l]-'A']--;
                l++;
            }

            ans = max(ans, (r-l+1));
            r++;
        }

        return ans;
    }
};
