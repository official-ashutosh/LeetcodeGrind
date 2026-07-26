class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());

        int n = nums.size();
        int ans = nums[0]*nums[1]*nums[2];
        ans = max(ans, nums[0]*nums[n-1]*nums[n-2]);
        return ans;
    }
};