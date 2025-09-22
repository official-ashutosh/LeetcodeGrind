class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int mx = 0;
        map<int, int> mp;

        for(auto i : nums) {
            mp[i]++;
            mx = max(mx, mp[i]);
        }

        int ans = 0;
        for(auto i : mp){
            if(i.second == mx) ans += mx;
        }

        return ans;

    }
};