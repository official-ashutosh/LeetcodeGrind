class Solution {
public:

    int func(int id, int m, int fl, vector<int> &a,
             vector<vector<vector<int>>> &dp) {

        int n = a.size();

        if(id >= n)
            return 0;

        if(dp[id][m][fl] != -1)
            return dp[id][m][fl];

        int ans;

        if(fl == 0){
            ans = 0;
            int sum = 0;

            for(int i=1; i<=2*m && id+i<=n; i++) {
                sum += a[id+i-1];

                ans = max(ans,
                    sum + func(id+i, max(m, i), 1, a, dp));
            }
        }
        else {
            ans = INT_MAX;

            for(int i=1; i<=2*m && id+i<=n; i++) {
                ans = min(ans,
                    func(id+i, max(m, i), 0, a, dp));
            }
        }

        return dp[id][m][fl] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(n + 1, vector<int>(2, -1))
        );

        return func(0, 1, 0, piles, dp);
    }
};