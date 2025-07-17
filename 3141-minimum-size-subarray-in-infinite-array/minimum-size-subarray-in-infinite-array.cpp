class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long sum = 0;
        for(auto i : nums) sum += i;

        int k = target/sum;
        int n = nums.size();
        int ans = n;

        target %= sum;
        if(target == 0) return n*k;

        map<long long, int> mp;
        mp[0] = 1;
        long long sum2 = 0;
        for(int i=0; i<2*n; i++){
            sum2 += nums[i%n];

            if(mp[sum2-target]){
                ans = min(ans, i+2-mp[sum2-target]);
            }

            mp[sum2] = i+2;
        }

        if(ans < n) return (ans+n*k);
        return -1;
    }
};