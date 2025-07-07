class Solution {
public:

    long long dp[100010];

    long long dfs(int v, int p, int k, vector<vector<pair<int,int>>> &g){
        multiset<long long> s;

        long long ans = 0;
        for(auto child : g[v]){
            if(child.second == p) continue;

            ans += dfs(child.second, v, k, g);
            if(child.first > dp[child.second]) s.insert(child.first - dp[child.second]);

            if(s.size() > k) s.erase(s.begin());
        }

        if(s.size() < k) dp[v] = 0;
        else dp[v] = *s.begin();

        for(auto i : s) ans += i;

        return ans;
    }

    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        
        int n = edges.size() + 1;  
        vector<vector<pair<int, int>>> g(n);

        for(auto i : edges){
            g[i[0]].push_back({i[2], i[1]});
            g[i[1]].push_back({i[2], i[0]});
        }

        memset(dp, 0, sizeof(dp));
        long long ans = dfs(0, -1, k, g); 
        return ans;
    }
};
