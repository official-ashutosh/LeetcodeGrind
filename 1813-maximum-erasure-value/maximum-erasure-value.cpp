class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mp;

        int l = 0, r= 0;

        int ans = 0;
        int  n = nums.size();
        int sum = 0;
        while(r < n){
            mp[nums[r]]++;
            sum += nums[r];

            while(mp[nums[r]] > 1){
                mp[nums[l]]--;
                sum -= nums[l];
                l++;
            }

            ans = max(ans, sum);
            r++;
        }

        return ans;
    }
};