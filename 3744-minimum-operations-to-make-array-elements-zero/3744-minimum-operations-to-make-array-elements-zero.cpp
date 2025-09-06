class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for(auto &i : queries) {
            long long sum = 0, k = 1;
            while(pow(4, k-1) <= i[1]) {
                long long l = pow(4, k-1);
                long long r = pow(4, k) - 1;
                if(l > i[1]) break;
                sum += k * max(0LL, min(i[1]*1LL, r)-max(i[0]*1LL, l) + 1);
                k++;
            }
            ans += (sum+1) / 2;
        }
        return ans;
    }
};
