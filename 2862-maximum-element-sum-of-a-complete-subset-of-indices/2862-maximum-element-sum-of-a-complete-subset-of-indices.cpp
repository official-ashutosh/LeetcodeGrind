class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        vector<int> v;
        v.push_back(1);
        int cr = 2;
        while(v.back() < n){
            v.push_back(cr*cr);
            cr++;
        }

        for(int i=1; i<=n; i++){
            long long ans2 = 0;
            for(auto j : v){
                int nid = i*j;
                if(nid > n) break;

                ans2 += nums[nid-1];
            }

            ans = max(ans, ans2);
        }

        return ans;
    }
};