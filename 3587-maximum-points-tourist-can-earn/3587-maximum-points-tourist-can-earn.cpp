class Solution {
public:

    int dp[210][210];

    int func(int id, int prev, int n, int k, vector<vector<int>> &a, vector<vector<int>> &b){
        if(id == k) return 0;

        if(dp[id][prev] != -1) return dp[id][prev];

        int ans = 0;
        for(int i=0; i<n; i++){
            if(prev == i){
                ans = max(ans, func(id+1, prev, n, k, a, b) + a[id][i]);
            } else {
                ans = max(ans, func(id+1, i, n, k, a, b) + b[prev][i]);
            }
        }

        return dp[id][prev] = ans;
    }

    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        memset(dp, -1, sizeof(dp));

        int ans = 0;
        for(int i=0; i<n;i++){
            ans = max(ans, func(0, i, n, k, stayScore, travelScore));
        }

        return ans;
    }
};