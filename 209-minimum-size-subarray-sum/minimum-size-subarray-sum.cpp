class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=0,n=nums.size(),s=0,ans=INT_MAX;
        while(r<n){
            s+=nums[r];
            while(s>=target){
                ans=min(ans,r-l+1);
                s-=nums[l];
                l++;
            }
            r++;
        }
        return ans==INT_MAX ? 0 : ans;
    }
};