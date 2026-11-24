class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();

        for(int i=0; i<n; i++){
            long long prod = nums[i];
            int gc = nums[i];
            long long lc = nums[i];
            for(int j=i+1; j<n; j++){
                prod *= nums[j];
                gc = __gcd(gc, nums[j]);
                lc = lcm(lc, nums[j]);
                if(prod > gc*lc) break;
                if(prod == gc*lc) ans = max(ans,j-i+1);
            }
        }

        return ans;
    }
};