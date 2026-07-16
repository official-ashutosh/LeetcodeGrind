class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx =0;
        vector<int> pre;
        for(auto i : nums){
            mx = max(mx, i);
            int gc = __gcd(mx, i);
            pre.push_back(gc);
        }

        sort(pre.begin(), pre.end());

        long long ans = 0;
        int  n = nums.size();
        for(int i=0; i<n/2; i++){
            long long gc = __gcd(pre[i], pre[n-1-i]);
            ans += gc;
        }

        return ans;
    }
};