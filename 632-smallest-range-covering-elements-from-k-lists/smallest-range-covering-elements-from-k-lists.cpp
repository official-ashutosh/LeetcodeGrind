class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> v;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(auto j : nums[i]){
                v.push_back({j, i});
            }
        }

        sort(v.begin(), v.end());

        int l = 0, ct = 0, r = 0;
        unordered_map<int, int> mp;
        int m = v.size();

        int le = 0, ri = INT_MAX;
        while(r < m){
            mp[v[r].second]++;

            if(mp[v[r].second] == 1) ct++;

            while(ct == n){
                int d = v[r].first - v[l].first;
                if(d < (ri-le)){
                    ri = v[r].first;
                    le = v[l].first;
                }

                mp[v[l].second]--;
                if(mp[v[l].second] == 0) ct--;
                l++;
            }
            r++;
        }
        return {le, ri};
    }
};