class Solution {
public:

    int dp[2010][55];
    static const int mod = 1e9+7;

    int func(int id, int p1, int p2, vector<int> &a){
        if(id == a.size()) return 1;


        if(dp[id][p1] != -1) return dp[id][p1];
        int n = a.size();
        int ans= 0;

        for(int i=0; i<=a[id]; i++){
            if(a[id]-i <= p2 && i >= p1){
                ans = (ans + func(id+1, i, a[id]-i, a)) % mod;
            }
        }
        return dp[id][p1] = ans;
    }

    int countOfPairs(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        
        int ans = func(0, 0, 51, nums);

        return ans;
    }
};