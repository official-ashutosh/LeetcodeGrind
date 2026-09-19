class Solution {
public:
    int dp[31][31][31];

    bool solve(string &s1, string &s2, int i, int j, int len){
        if(dp[i][j][len] != -1)
            return dp[i][j][len];

        if(s1.substr(i, len) == s2.substr(j, len))
            return dp[i][j][len] = 1;

        int cnt[26] = {};
        for(int k=0; k<len; k++){
            cnt[s1[i+k]-'a']++;
            cnt[s2[j+k]-'a']--;
        }

        for(auto c : cnt){
            if(c) return dp[i][j][len] = 0;
        }

        for(int k=1; k<len; k++){
            // No swap
            if(solve(s1, s2, i, j, k) &&
                solve(s1, s2, i+k, j+k, len-k))
                return dp[i][j][len] = 1;

            // Swap
            if(solve(s1, s2, i, j+len-k, k) &&
                solve(s1, s2, i+k, j, len-k))
                return dp[i][j][len] = 1;
        }

        return dp[i][j][len] = 0;
    }

    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;

        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, 0, 0, s1.size());
    }
};