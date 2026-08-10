class Solution {
public:
    bool func(int n, vector<int>& v, vector<int>& dp) {
        if(n == 0) return false;

        if(dp[n] != -1)
            return dp[n];

        for(auto x : v) {
            if(x > n) break;

            if(!func(n-x, v, dp))
                return dp[n] = true;
        }

        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {
        vector<int> v;

        for(int i=1; i*i<=n; i++)
            v.push_back(i*i);

        vector<int> dp(n+1, -1);

        return func(n, v, dp);
    }
};