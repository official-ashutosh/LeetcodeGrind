class Solution {
public:

    int dp[1010][1010][2];
    const int mod = 1e9+7;
    long long func(int n, int k, int fl){
        if(k == 0) return 1;
        if(n <= 0) return 0;

        if(dp[n][k][fl] != -1) return dp[n][k][fl];

        long long ans = 0;
        if(fl){
            ans = (ans + func(n-1, k, fl)) % mod;
            ans = (ans + func(n, k-1, 0)) % mod;


        } else {
            ans = (ans + func(n-1, k, 0)) % mod;
            ans = (ans + func(n-1, k, 1)) % mod;

        }

        return dp[n][k][fl] = ans;

    }
    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof(dp));

        int ans = func(n, k, 0);
        return ans;
    }
};