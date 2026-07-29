class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0;
        for(auto i : nums) xr ^= i;

        int mx = 0;
        for(int i=32; i>=0; i--){
            if((1ll<<i) & xr){
                mx = i;
                break;
            }
        }

        int ans1 = 0, ans2 = 0;

        for(auto i : nums){
            if(i & (1ll<<mx) ) ans1 ^= i;
            else ans2 ^= i;
        }

        return {ans1, ans2};
    }
};