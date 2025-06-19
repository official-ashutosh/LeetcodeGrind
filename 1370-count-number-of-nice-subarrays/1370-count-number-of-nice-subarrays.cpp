class Solution {
public:

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        long long ans1 = 0, ans2 = 0;

        int l = 0, r= 0; 
        long long sum1 = 0;

        while(r < n){
            sum1 += nums[r];
            while(sum1 > goal){
                sum1 -= nums[l];
                l++;
            }
            ans1 += (r-l+1);
            r++;
        }

        if(goal > 0){
            l = 0; 
            long long sum2 = 0;
            r = 0;
            while(r < n){
                sum2 += nums[r];
                while(sum2 > goal-1){
                    sum2 -= nums[l];
                    l++;
                }
                ans2 += r-l+1;
                r++;
            }
        }

        return (ans1-ans2);
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        for(auto &i : nums) i %= 2;

        return numSubarraysWithSum(nums, k);
    }
};