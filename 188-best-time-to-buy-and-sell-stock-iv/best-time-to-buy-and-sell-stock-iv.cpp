class Solution {
public:

    int func(int id, int k, int fl, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(k == 0) return 0;
        if(id == prices.size()) {
            if(!fl) return 0;
            return INT_MIN;
        }

        if(dp[id][k][fl] != -1) return dp[id][k][fl];

        long long ans = INT_MIN;
        ans = max(ans, 1ll*func(id+1,k, fl, prices, dp));
        if(fl){
            ans = max(ans, 1ll*func(id+1,k-1, 0, prices, dp) + prices[id]);
        } else {
            ans = max(ans, 1ll*func(id+1,k, 1, prices, dp) - prices[id]);
        }
        return dp[id][k][fl] = ans;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(3, -1)));
        return func(0, k, 0, prices, dp);
    }
};