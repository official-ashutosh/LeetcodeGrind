class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int l = 0, r = 0;
        int ans = 1;

        int n = s.size();

        if(n == 0) return 0;

        vector<int> mp(256, 0);
        while(r < n){
            mp[s[r]]++;
            while(mp[s[r]] > 1 && l < r){
                mp[s[l]]--;
                l++;
            }

            ans = max(ans, r-l+1);

            // cout << l << " " << r<< endl;
            r++;
        }

        return ans;
    }
};