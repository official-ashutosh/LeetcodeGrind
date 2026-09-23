class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        vector<int> pre(n+1, 0), suff(n+1, 0);
        for(int i=0; i<n; i++){
            pre[i+1] = pre[i] + nums[i];
        }

        for(int i=n-1; i>=0; i--){
            suff[i] = suff[i+1]+nums[i];
        }

        int r = 0;
        int ans = n+1;
        for(int l=0; l<n; l++){
            while(r < n && pre[l]+suff[r] > x){
                r++;

            }

            if(pre[l]+suff[r] == x){
                ans = min(ans, l+(n-r));
            }
        }

        if(ans == n+1) ans = -1;
        return ans;
    }
};