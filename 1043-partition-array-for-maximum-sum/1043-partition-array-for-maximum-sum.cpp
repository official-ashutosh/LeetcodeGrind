class Solution {
public:
    int solve(int i, vector<int>& arr, int k, vector<int>& dp) {
        if(i == arr.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int mx = 0, ans = 0;

        for(int j = i; j < min((int)arr.size(), i + k); j++) {
            mx = max(mx, arr[j]);
            ans = max(ans, mx * (j - i + 1) + solve(j + 1, arr, k, dp));
        }

        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);

        return solve(0, arr, k, dp);
    }
};