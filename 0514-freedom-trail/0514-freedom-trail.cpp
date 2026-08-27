class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();

        vector<vector<int>> dp(m+1, vector<int>(n, 1e9));
        dp[0][0] = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(dp[i][j] == 1e9) continue;

                for(int k=0; k<n; k++){
                    if(ring[k] != key[i]) continue;

                    int d = abs(j-k);
                    d = min(d, n-d);

                    dp[i+1][k] = min(dp[i+1][k], dp[i][j]+d+1);
                }
            }
        }

        return *min_element(dp[m].begin(), dp[m].end());
    }
};