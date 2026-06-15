class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mn = nums[0], mx = nums[0];
        for(auto i : nums) {
            mn = min(mn, i);
            mx = max(mx, i);
        }
    long long ans = (long long)(mx-mn)*k;
    return ans;
    }
};