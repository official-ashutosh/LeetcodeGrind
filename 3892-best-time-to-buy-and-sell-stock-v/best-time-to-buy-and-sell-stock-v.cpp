class Solution {
public:

    long long dp[1010][1010][2][3];
    long long func(int id, int k, int p, int fl, vector<int>&a){
        if(id == a.size()){
            if(p == 0) return 0LL;
            return LLONG_MIN;
        }

        if(k < 0) return LLONG_MIN;
        if(dp[id][k][p][fl] != -1) return dp[id][k][p][fl];

        long long ans = LLONG_MIN;
        if(p == 0){

            long long ccc = func(id+1, k, p, fl, a);
            ans = max(ans, ccc);
            if(k > 0) {

                ccc = func(id+1, k-1, 1, 1, a);
                if(ccc != LLONG_MIN) ans = max(ans, ccc-a[id]);
                ccc = func(id+1, k-1, 1, 0, a);
                if(ccc != LLONG_MIN) ans = max(ans, ccc+a[id]);
            }
        } else {

            long long ccc = func(id+1, k, 1, fl,a);
            ans = max(ans, ccc);
            
            if(fl) {
                ccc = func(id+1, k, 0, 0, a);
                if(ccc != LLONG_MIN) ans = max(ans, ccc+a[id]);
            }
            else {

                ccc = func(id+1, k, 0, 0, a);
                if(ccc != LLONG_MIN) ans = max(ans, ccc-a[id]);
            }
        }

        return dp[id][k][p][fl] = ans;
    }
    
    long long maximumProfit(vector<int>& prices, int k) {
        memset(dp, -1, sizeof(dp));
        long long ans = func(0, k, 0, 0, prices);
        return ans;
    }
};