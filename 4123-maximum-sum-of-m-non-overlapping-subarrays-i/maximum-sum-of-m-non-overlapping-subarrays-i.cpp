class Solution {
public:

    long long dp[1010][1010];

    long long func(int id, int m, int l, int r, vector<int> &nums){
        if(id >= nums.size() || m == 0) return 0;

        if(dp[id][m] != -1) return dp[id][m];

        long long ans = func(id+1, m, l,r, nums);
        long long sum = 0,ct = 0;
        for(int i=id; i<min((int)nums.size(),id+r); i++){
            sum += nums[i];
            ct++;
            if(ct >= l && ct < r-l) ans = max(ans, func(i+2, m-1, l,r, nums)+sum);
            else if(ct >= l) ans = max(ans, func(i+1, m-1, l,r, nums)+sum);


        }

        return dp[id][m]= ans;

    }
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
    

            int ct = 0;
            long long sum = 0;
            for(int i=0; i<l; i++) sum += nums[i];
            long long ans = sum;

            for(int i=l; i<nums.size(); i++){
                long long sum2 = 0;
                for(int j=i; j<min((int)nums.size(),i+(r-l)); j++){
                    sum2 += nums[j];
                    ans = max(ans, sum+sum2);
                }

                sum -= nums[i-l];
                sum += nums[i];
                ans = max(ans, sum);


            }
        if(ans <= 0){
            return ans;
        }

        memset(dp, -1, sizeof(dp));
        return func(0,m, l, r, nums);


    }
};