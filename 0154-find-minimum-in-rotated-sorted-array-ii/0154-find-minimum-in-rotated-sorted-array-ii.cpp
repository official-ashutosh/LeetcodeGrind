class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int l=0, r=n-1, ans = nums[0];    

        while(l < r) {
            int mid = (l+r) / 2;

            if(nums[mid] == nums[r]) r--;
            else 
            if(nums[mid] > nums[r]) {
                
                l = mid+1;
            } else {

                ans = min(ans, nums[mid]);
                r = mid;
            } 
        }

        return nums[l];
    }
};