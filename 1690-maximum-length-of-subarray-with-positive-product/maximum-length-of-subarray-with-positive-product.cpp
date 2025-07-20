class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans = 0;
        long long p1 = 1, p2 = 1, p3 = 1;
        int n = nums.size();

        int l1 = -1, l2 = -1, r = n;

        for(int i=0; i<n; i++) {

            if(nums[i] < 0){
                p1 *= -1;
                p2 *= -1;
            } else if(nums[i] == 0){
                p1 = 0;
                p2 = 0;
            }
            
            if(nums[n-i-1] < 0) p3 *= -1;
            else if(nums[n-i-1] == 0) p3 = 0;

            if(p1 > 0) ans = max(ans, i-l1);
            if(p2 > 0) ans = max(ans, i-l2);
            if(p3 > 0) ans = max(ans, r-(n-1-i));

            if(p1 == 0) {
                p1 = 1;
                l1 = i;
            }

            if(p2 <= 0) {
                p2 = 1;
                l2 = i;
            }
            if(p3 == 0) {
                p3 = 1;
                r = n-1-i;
            }
        }

        return ans;
    }
};
