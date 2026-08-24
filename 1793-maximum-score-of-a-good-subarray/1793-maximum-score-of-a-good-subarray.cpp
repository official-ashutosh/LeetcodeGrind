class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();

        int l = k-1, r = k+1, mn = nums[k];
        long long ans = nums[k];
        while(true){
            if(r >= n && l < 0) return ans;
            if(l >= 0 && nums[l] > nums[r]){
                mn = min(mn, nums[l]);
                l--;
            } else {
                mn = min(mn, nums[r]);
                r++;
            }
            ans = max(ans, mn*1ll*(r-l-1));
        }

        return ans;
    }
};