class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();

        int l = 1, r = 1e9, ans = r;
        while(l <= r){
            int mid = (l+r)/2;

            int ct = 0;
            for(auto i : nums){
                ct += (i+mid-1)/mid - 1;
                if(ct > maxOperations) break;
            }

            if(ct > maxOperations) l = mid + 1;
            else {
                ans = mid;
                r = mid-1;
            }
        }

        return ans;
    }
};