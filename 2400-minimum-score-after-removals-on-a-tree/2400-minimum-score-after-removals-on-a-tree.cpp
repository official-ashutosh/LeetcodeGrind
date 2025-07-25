class Solution {
public:
    vector<int> g[100010];  
    vector<int> subXor;  
    vector<int> par;       

    void dfs(int u, int p, vector<int>& nums) {
        subXor[u] = nums[u];
        par[u] = p;
        for(auto v : g[u]) {
            if(v != p) {
                dfs(v, u, nums);
                subXor[u] ^= subXor[v];
            }
        }
    }

    bool check(int u, int v) {   // u child of v

        while(u != -1) {
            if(u == v) return true;
            u = par[u];
        }
        return false;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        subXor.resize(n);
        par.resize(n, -1);

        for(auto& i : edges) {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }

        dfs(0, -1, nums);
        int totXor = subXor[0];

        int ans = INT_MAX;

        for(int i=1; i<n; i++) {
            for(int j=i+1; j<n; j++) {

                if(check(i, j)) {
                    int x = subXor[i];
                    int y = subXor[j] ^ subXor[i];
                    int z = totXor ^ subXor[j];
                    ans = min(ans, max({x, y, z}) - min({x, y, z}));
                } else if(check(j, i)) {
                    int x = subXor[j];
                    int y = subXor[i] ^ subXor[j];
                    int z = totXor ^ subXor[i];
                    ans = min(ans, max({x, y, z}) - min({x, y, z}));
                } else {
                    int x = subXor[i];
                    int y = subXor[j];
                    int z = totXor^x^y;
                    ans = min(ans, max({x, y, z}) - min({x, y, z}));
                }
            }
        }

        return ans;
    }
};
