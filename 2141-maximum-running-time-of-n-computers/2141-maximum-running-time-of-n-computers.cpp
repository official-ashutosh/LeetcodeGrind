class Solution {
public:
    long long maxRunTime(int n, vector<int>& b) {
        sort(b.begin(), b.end());
        long long ans = 0;

        long long sum = 0;
        for(auto i : b) sum += i;

        long long l = 1, r = sum/n;

        while(l <= r){
            long long mid = (r-l)/2 + l;

            long long sum2 = 0;
            for(auto i : b){
                sum2 += min(i*1ll, mid);
            }

            if(sum2 >= n*mid) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }

        return ans;
    }
};