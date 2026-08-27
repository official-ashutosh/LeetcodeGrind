class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int func(string &ring, string &key, int i, int pos){
        if(i == key.size()) return 0;

        if(dp[i][pos] != -1) return dp[i][pos];

        int ans = 1e9;

        for(int j=0; j<n; j++){
            if(ring[j] == key[i]){
                int d = abs(pos-j);
                d = min(d, n-d);

                ans = min(ans, d+1 + func(ring, key, i+1, j));
            }
        }

        return dp[i][pos] = ans;
    }

    int findRotateSteps(string ring, string key) {
        n = ring.size();
        dp.assign(key.size(), vector<int>(n, -1));

        return func(ring, key, 0, 0);
    }
};