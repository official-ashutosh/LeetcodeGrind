class Solution {
public:
    const int mod = 1e9+7;
    int inv2 = 500000004;
    int countNicePairs(vector<int>& nums) {
        map<int, int> mp;

        for(auto i : nums){
            int a = i;
            int b = 0;
            while(a > 0){
                int x =  (a % 10);
                b = b * 10 + x;
                a /= 10;
            }

            mp[i-b]++;
        }

        long long ans = 0;
        for(auto i : mp){
            int ct = i.second;
            long long pairs = 1LL * ct * (ct - 1) % mod;
pairs = pairs * inv2 % mod;
ans = (ans + pairs) % mod;
        }

        return ans;
    }
};