class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        long long ans = 0;
        vector<int> v;
        for(auto i : values){
            for(auto j : i){
                v.push_back(j);
            }
        }

        sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++){
            ans += (i+1)*1ll*v[i];
        }

        return ans;
    }
};