class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        int l = 0, r = 0;
        int ans = 0;

        vector<int> ct(3, 0); 

        while(r < n){
            ct[s[r]-'a']++;

            while(ct[0] > 0 && ct[1] > 0 && ct[2] > 0){
                ans += n - r;
                ct[s[l]-'a']--;
                l++;
            }

            r++;
        }

        return ans;
    }
};
