class Solution {
public:

    int dp[52][52][52][52];

    static const int mod = 1e9+7;

    int func(int id, int lst, int ct, int prev1, int prev2, vector<int> &nums){
        if(ct == 0) {
            return abs(nums[prev1]-nums[prev2]);
        }

        if(id == nums.size() || ct < 0){
            return 0;
        }

        if(dp[lst+1][ct][prev1+1][prev2+1] != -1) return dp[lst+1][ct][prev1+1][prev2+1];

        long long ans = 0;

        ans = (ans+func(id+1, lst, ct, prev1, prev2, nums))%mod;

        if(lst == -1){
            ans = (ans+func(id+1, id, ct-1, prev1, prev2, nums)) % mod;
            
        } else {
            if(prev1 == -1 || prev2 == -1 || abs(nums[id]-nums[lst]) < abs(nums[prev1]-nums[prev2]) ){
                ans = (ans+func(id+1, id, ct-1, lst, id, nums)) % mod;
            } else {
                ans = (ans+func(id+1, id, ct-1, prev1, prev2, nums)) % mod;
            }
        }

        return dp[lst+1][ct][prev1+1][prev2+1] = ans;
    }

    int sumOfPowers(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        memset(dp, -1, sizeof(dp));

        return func(0, -1, k, -1, -1, nums);
    }
};