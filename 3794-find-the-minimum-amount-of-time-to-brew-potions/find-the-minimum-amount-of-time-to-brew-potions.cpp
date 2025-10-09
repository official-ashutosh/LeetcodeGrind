class Solution {
public:
    long long minTime(vector<int>& mana, vector<int>&skill) {
        int n = skill.size();  
        int m = mana.size();   
        vector<long long> dp(m, 0);
        dp[0] = 1LL*skill[0] * mana[0];
        for (int j = 1; j < m; j++) dp[j] = dp[j - 1] + 1LL*skill[0] * mana[j];

        vector<long long> pre(m);
        pre[0] = mana[0];
        for(int j=1; j<m; j++) {
            pre[j] = pre[j-1] + mana[j];
        }
        for (int i = 1; i < n; i++) {
            long long l = dp[0];

            for(int j=1; j<m; j++) {
                l = max(l, dp[j] - 1LL*skill[i]*pre[j-1]);
            }
            vector<long long> v(m);
            v[0] = l + 1LL*skill[i] * mana[0];
            for (int j = 1; j < m; j++) {
                v[j] = v[j-1] + 1LL*skill[i] * mana[j];
            }dp = v;
        }
        return dp[m - 1];
    }
};