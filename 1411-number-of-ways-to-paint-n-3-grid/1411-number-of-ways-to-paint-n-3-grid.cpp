class Solution {
public:
    const int mod = 1e9+7;
    int dp[5010][4][4][4];
    int solve(int id, int prev1, int prev2, int prev3){
        if(id == 0) return 1;
        
        if(dp[id][prev1][prev2][prev3] != -1){
            return dp[id][prev1][prev2][prev3];
        }

        int ans = 0;
        for(int i=1; i<=3; i++){
            if(i == prev1) continue;
            for(int j=1; j<=3; j++){
                if(j == prev2 || j == i)continue;
                
                for(int k=1; k<=3; k++){
                    if(k == prev3 || k == j) continue;
                    ans = (ans + solve(id-1, i, j, k)) % mod;
                }
            }
        }
        return dp[id][prev1][prev2][prev3] = ans;
    }

    int numOfWays(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n, 0, 0, 0);
    }
};