class Solution {
public:

    int dp[1010];
    static const int mod = 1e9+7;

    int func(int id, int d, int f, int n){
        if(id+d > n) return 1;

        if(dp[id] != -1) return dp[id];

        long ans = 1;
        for(int i=id+d; i<min(n, id+f); i++){
            ans = (ans + func(i, d, f, n)) % mod;
        }

        if(id+f <= n){
            ans = (ans-1+mod)%mod;
        } else {
            ans = (ans + func(n, d, f, n)) % mod;
        }

        return dp[id] = ans;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        memset(dp, -1, sizeof(dp));

        int ans= func(1, delay, forget, n);
        return ans;
    }
};