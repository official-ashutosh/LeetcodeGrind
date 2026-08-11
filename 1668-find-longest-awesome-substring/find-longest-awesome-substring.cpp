class Solution {
public:
    int longestAwesome(string s) {

        int n = s.size();

        vector<vector<int>> pre(n+1, vector<int>(10, 0));

        int m = (1<<10)+1;
        vector<int> v(m, n);

        int ans = 1;
        int mask = 0;
        v[0] = -1;
        for(int i=0; i<n; i++){
            mask ^= (1<<(s[i]-'0'));
            if(v[mask] != n){
                ans = max(ans, i-v[mask]);
            }

            for(int j=0; j<10; j++){
                int nmask = (mask ^ (1<<j));

                if(v[nmask] != n){
                    ans = max(ans, i-v[nmask]);
                }
            }

            v[mask] = min(i, v[mask]);
        }

        return ans;
        
    }
};