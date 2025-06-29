int mod = 1e9+7;

class Solution {
public:


    int binexp(int a, int b, int m){
        a %= m;
        int result = 1;
        while(b > 0){
            if(b & 1){
                result = (result * 1LL * a) % m;
            }
            a = (a * 1LL * a) % m;
            b >>= 1;
        }
        return result;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        long long ans = 0;

        int n = nums.size();
        for(int i=0; i<n; i++){
            auto it = upper_bound(nums.begin(), nums.end(), target-nums[i]);

            if(it == nums.begin()) continue;
            it--;

            int d = (it-nums.begin()-i);
            if(d < 0) continue;

            ans = (ans + binexp(2, d, mod)) % mod;
        }

        return ans;
    }
};