class Solution {
public:

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long sum1 = 0, sum2 = 0;
        for(int i=0; i<n; i++){
            long long sum3 = 0, sum4 = 0;
            sum3 = max(sum1, sum2+nums[i]);
            sum4 = max(sum2, sum1-nums[i]);

            sum1 = sum3;
            sum2 = sum4;
        }
        return sum1;
    }
};