class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0, ct = 0;
        int n = nums.size();
        for(auto i : nums){
            xr ^= i;
            if(i) ct++;
        }

        if(xr) return n;
        if(!ct) return 0;
        return n-1;
    }
};