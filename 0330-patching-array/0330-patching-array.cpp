class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        
        long long x = 0, miss = 1, ans = 0, i =0;
        while(miss <= n){
            if(i < nums.size() && miss >= nums[i]){
                miss += nums[i];
                i++;
            } else {
                miss += miss;
                ans++;
            }
        }

        return ans;
    }
};