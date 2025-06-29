class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        long long sum = 0;

        for(auto i : nums) sum += i;

        if(sum < target) return -1;

        sort(nums.begin(), nums.end());

        int ans = 0;

        while(target > 0){
            
            int k = nums.back();
            nums.pop_back();

            if(sum-k >= target) sum -= k;
            else if(k <= target){
                sum -= k;
                target -= k;

            } else {
                ans++;

                nums.push_back(k/2);
                nums.push_back(k/2);

            }
        }

        return ans;
    }
};