class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int mx = 0;

        int n = nums.size();
        for(int i=1; i<n; i++){
            mx = max(mx, abs(nums[i]-nums[i-1]));
        }

        mx = max(mx, abs(nums[0]-nums[n-1]));

        return mx;
    }
};