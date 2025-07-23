class Solution {
public:

    long long minimumDifference(vector<int>& nums) {
        int m = nums.size();
        int n = m/3;


        multiset<int, greater<int>> maxx;   
        multiset<int> minn;
        vector<long long> pre(m,0), suff(m, 0);

        long long sum = 0;
        for(int i=0; i<m; i++){
            maxx.insert(nums[i]);

            sum += nums[i];

            if(maxx.size() > n){
                sum -= (*maxx.begin());
                maxx.erase(maxx.begin());
            }

            if(i >= n-1) pre[i] = sum;
        }    

        sum = 0;
        for(int i=m-1; i>=0; i--){
            minn.insert(nums[i]);

            sum += nums[i];

            if(minn.size() > n){
                sum -= (*minn.begin());
                minn.erase(minn.begin());
            }

            if(i <= 2*n) suff[i] = sum;
        }

        long long ans = 1e18;
        for(int i=n-1; i<2*n; i++){
            ans = min(ans, pre[i]-suff[i+1]);
        }

        return ans;
    }
};