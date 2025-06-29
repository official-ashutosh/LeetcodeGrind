class Solution {
public:

    int dp[110][110][110];

    static const int mod = 1e9 + 7;

    int binexp(int a, int b, int m){
        a %= m;
        int result = 1;
        while(b > 0){
            if(b & 1){
                result = (result * 1LL * a) % m;
            }
            a = (a * 1LL * a) % m;
            b >>= 1;
        }
        return result;
    }

    long long func(int id, int ct,  int tar, vector<int> &a){
        if(tar == 0) return binexp(2, a.size()-ct, mod);

        if(id == a.size() || tar < 0) return 0;
        if(dp[id][tar][ct] != -1) return dp[id][tar][ct];

        long long ans = func(id+1, ct, tar, a);
        ans = (ans + func(id+1, ct+1, tar-a[id], a)) % mod;

        return dp[id][tar][ct] = ans;

    }

    int sumOfPower(vector<int>& nums, int k) {
        long long ans = 0;
        
        memset(dp, -1, sizeof(dp));
        ans = (ans + func(0, 0, k, nums)) % mod;

        return ans;
    }
};