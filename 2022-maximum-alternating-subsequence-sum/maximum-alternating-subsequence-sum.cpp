class Solution {
public:

    long long func(int id, int fl, vector<int> &a, vector<vector<long long>> &dp){
        if(id == a.size()) return 0ll;
        if(dp[id][fl] != -1) return dp[id][fl];

        long long ans = 0;
        ans = max(ans, func(id+1, fl, a, dp));
        if(fl){
            ans = max(ans, func(id+1, 0, a, dp) - a[id]);
        } else {
            ans = max(ans, func(id+1, 1, a, dp) + a[id]);
        }

        return dp[id][fl] = ans;
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n+1, vector<long long>(2, -1));
        long long ans = func(0, 0, nums, dp);
        return ans;
    }
};