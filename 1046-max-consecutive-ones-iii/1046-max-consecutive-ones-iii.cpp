class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ct = 0;

        int n = nums.size();
        int r = 0, l = 0;

        int ans = 0;

        while(r < n){
            if(nums[r] == 0) ct++;
            while(ct > k && l <= r){
                if(nums[l] == 0) ct--;
                l++;
            }

            ans = max(ans, r-l+1);
            r++;
        }

        return ans;
    }
};