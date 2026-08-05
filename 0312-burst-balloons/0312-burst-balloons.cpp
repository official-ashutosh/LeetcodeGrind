class Solution {
public:

    // 3 1 5 8

    int func(int l, int r, vector<int> &a, vector<vector<int>> &dp){
        if(l > r) return 0;

        int n = a.size();
        if(l == r){
            int ans = a[l];
            if(l > 0) ans *= a[l-1];
            if(r < n-1) ans *= a[r+1];

            return ans;
        }

        if(dp[l][r] != -1) return dp[l][r];

        int ans = 0;
        for(int i=l; i<=r; i++){
            int ans2 = a[i];

            if(l > 0) ans2 *= a[l-1];
            if(r < n-1) ans2 *= a[r+1]; 
            ans2 += func(l, i-1, a, dp) + func(i+1, r, a, dp);
            ans = max(ans, ans2);
        }

        return dp[l][r] = ans;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> a = {1};
        for(auto i : nums) a.push_back(i);

        a.push_back(1);

        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        int ans = func(0, n-1, a, dp);
        return ans;
    }
};