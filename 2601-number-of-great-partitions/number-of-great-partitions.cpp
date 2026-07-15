class Solution {
public:
    const int mod = 1e9+7;
    int countPartitions(vector<int>& nums, int k) {
        long long sum = 0, ans = 1;

        vector<long long> dp(k);
        dp[0]  = 1;

        for(auto i : nums){
            for(int j=k-1-i; j>=0; j--){
                dp[j+i] = (dp[j+i]+dp[j]) % mod;
            }

            ans = (ans*2) % mod;

            sum += i;
        }

        int n = nums.size();
        // ans = ((1ll<<n) % mod);

        long long ans2 = 0;
        for(int i=0; i<k; i++){
            if(sum-i < k) ans2 += dp[i];
            else ans2 += (dp[i]*2);
        }

        int ret = ((ans-ans2)%mod+mod) % mod;
        return ret;

    }
};