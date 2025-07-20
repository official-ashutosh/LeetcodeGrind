class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int, int> mp;

        long long ans = 0;
        int p = 0;
        mp[0] = 1;

        for(auto i : word){
            int c = i-'a';

            p ^= (1<<c);
            ans += mp[p];  // sare even ke liye

            for(int i=0; i<10; i++){
                ans += mp[p^(1<<i)];  // 1 odd 
            }

            mp[p]++;
        }

        return ans;
    }
};