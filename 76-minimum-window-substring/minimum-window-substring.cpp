class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp, mp2;
        for(auto i : t) mp[i]++;
        
        int m = t.size();
        int l = 0, r = 0;
        int ans = INT_MAX, le = 0;

        int ct = 0;
        while(r < s.size()) {
            char c = s[r];
            mp2[c]++;
            if(mp2[c] <= mp[c])  ct++;
    
            while(ct == m) {
                if(r-l+1 < ans) {
                    ans = r-l+1;
                    le = l;
                }
                char d = s[l];
                mp2[d]--;
                if(mp2[d] < mp[d]) ct--;
                l++;
            }
            r++;
        }

        return ans == INT_MAX ? "" : s.substr(le, ans);
    }
};
