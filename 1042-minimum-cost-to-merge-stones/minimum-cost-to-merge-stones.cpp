class Solution {
public:

    int func(int l, int r, int k, vector<int> &a, vector<int> &pre, vector<vector<int>> &dp){

        if(l == r) return 0;
        if(dp[l][r] != -1) return dp[l][r];

        int ans = 1e9;
        for(int i=l; i<r; i+=k-1){
            ans = min(ans, func(l, i, k, a, pre, dp) + func(i+1, r, k, a, pre, dp));
        }

        if((r-l) % (k-1) ==0) ans += pre[r]-pre[l-1];

        return dp[l][r] = ans;
    }

    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if((n-1) % (k-1)) return -1;

        vector<int> pre(n+1, 0);
        for(int i=1; i<=n; i++){
            pre[i] = pre[i-1] + stones[i-1];
        }

        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        int ans = func(1, n, k, stones, pre, dp);
        return ans;

    }
};