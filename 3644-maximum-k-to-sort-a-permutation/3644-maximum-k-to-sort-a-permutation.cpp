class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = (1ll<<31) - 1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != i) ans &= nums[i];
        }
        if(ans == (1ll<<31)-1) ans = 0;
        return ans;
    }
};