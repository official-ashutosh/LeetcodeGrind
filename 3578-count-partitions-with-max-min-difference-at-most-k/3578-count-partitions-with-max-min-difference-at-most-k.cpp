class Solution {
public:

    static const int MOD = 1e9+7;
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> pre(n+1, 0), v(n+1, 0);
        pre[0] = 1;
        v[0] = 1;

        deque<int> maxx, minn;
        int l = 0;
        int r = 0;
        long long ans = 0;
        while(r < n){
            while(!maxx.empty() && nums[r] > maxx.back()) maxx.pop_back();
            maxx.push_back(nums[r]);

            while(!minn.empty() && nums[r] < minn.back()) minn.pop_back();
            minn.push_back(nums[r]);

            while(!maxx.empty() && !minn.empty() && (maxx.front()-minn.front()) > k){
                if(nums[l] == minn.front()) minn.pop_front();
                if(nums[l] == maxx.front()) maxx.pop_front();

                l++;
            }

            long long p = pre[r];
            if(l > 0) p -= pre[l-1];

            v[r+1] = (p + MOD) % MOD;

            pre[r+1] = (pre[r] + v[r+1]) % MOD;
            ans = v[r+1];
            
            r++;
            
        }

        return ans;

        
    }
};