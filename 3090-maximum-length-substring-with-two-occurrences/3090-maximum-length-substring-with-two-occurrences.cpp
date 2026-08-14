class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size(), ans = 0;
        vector<int> cnt(26, 0);
        
        for(int l=0, r=0; r<n; r++){
            cnt[s[r]-'a']++;
            
            while(cnt[s[r] - 'a'] > 2){
                cnt[s[l]-'a']--;
                l++;
            }
            
            ans = max(ans, r - l + 1);
        }
        
        return ans;
    }
};