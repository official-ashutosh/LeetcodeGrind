class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> g(n);
        vector<int> indeg(n, 0), dp(n, 0);

        for(auto &i : relations){
            int u = i[0]-1;
            int v = i[1]-1;
            g[u].push_back(v);
            indeg[v]++;
        }

        queue<int> q;

        for(int i=0; i<n; i++){
            dp[i] = time[i];
            if(indeg[i] == 0) q.push(i);
        }

        int ans = 0;

        while(!q.empty()) {
            auto u = q.front();
            q.pop();

            ans = max(ans, dp[u]);

            for(auto v : g[u]){
                dp[v] = max(dp[v], dp[u]+time[v]);

                indeg[v]--;

                if(indeg[v] == 0) q.push(v);
            }
        }

        return ans;
    }
};