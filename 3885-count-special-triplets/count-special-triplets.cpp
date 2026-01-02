class Solution {
public:

    static const int MOD = 1e9 + 7;
    
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        // factorial();

        map<long long, long long> mp1, mp2;
        for(int i=n-1; i>0; i--) mp2[nums[i]]++;

        long long ans = 0;
        int fl = 0;
        mp1[nums[0]]++;
        for(int i=1; i<n-1; i++){
            mp2[nums[i]]--;
            // if(nums[i] % 2 == 0){
                long long p = nums[i]*2;
                ans = (ans + (mp1[p]*mp2[p]*1ll) % MOD) % MOD;
            // }
            // cout << mp2[p] << " " << mp1[p] << endl;
            mp1[nums[i]]++;
        }

        return ans;

        
    }
};