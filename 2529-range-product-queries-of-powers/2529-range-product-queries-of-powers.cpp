class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> vi;
        for(int i=0; i<32; i++){
            if(n & (1<<i)) vi.push_back(1<<i);

        }

        int mod = 1e9+7;

        vector<int> ans;
        for(auto i : queries){
            int l = i[0], r = i[1];

            long long sm = 1;
            while(l <= r){
                sm = (sm*1ll*vi[l]) % mod;
                l++;
            }
            ans.push_back(sm);
        }

        return ans;
    }
};