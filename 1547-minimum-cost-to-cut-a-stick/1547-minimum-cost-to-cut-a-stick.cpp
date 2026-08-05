class Solution {
public:

    long long func(int l, int r, vector<int> &a, vector<vector<int>> &dp){
        if(l > r) return 0;
        if(dp[l][r] != -1) return dp[l][r];

        long long ans = 1e9;
        for(int i=l; i<=r; i++){

            long long ans2 = a[r+1]-a[l-1];

            ans2 += func(l, i-1, a, dp) + func(i+1, r, a, dp);

            ans = min(ans, ans2);
        }

        return dp[l][r] = ans;
    }

    int minCost(int n, vector<int>& cuts) {

        sort(cuts.begin(), cuts.end());

        vector<int> a= {0};
        for(auto i : cuts) a.push_back(i);
        a.push_back(n);

        int m = a.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1, -1));
        int ans = func(1, m-2, a, dp);
        return ans;
    }
};