class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MIN;
        int p1 = 1, p2 = 1, p3 = 1;
        for(int i=0; i<n; i++){
            p1 *= nums[i];
            p2 *= nums[i];
            p3 *= nums[n-1-i];
            ans = max({ans, p1, p2, p3});
            if(p3 == 0) p3 = 1;
            if(p1 == 0) p1 = 1;
            if(p2 <= 0) p2 = 1;
        }

        return ans;


    }
};