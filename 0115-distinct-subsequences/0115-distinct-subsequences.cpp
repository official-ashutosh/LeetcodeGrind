class Solution {
public:

    int dp[1010][1010];

    int func(int i, int j, string &s, string &t){
        if(j < 0) return 1;
        if(i < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;

        if(s[i] == t[j]){
            ans += func(i-1, j-1, s, t);
        }
        ans += func(i-1, j, s, t);
        // ans += func(i, j-1, s, t);

        return dp[i][j] = ans;

    }

    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        return func(s.size()-1, t.size()-1, s, t);
    }
};