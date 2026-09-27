class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<int> ans;

    void dfs1(int u, int p){
        for(auto it : adj[u]){
            int v = it.first;
            int cost = it.second;

            if(v == p) continue;

            ans[0] += cost;
            dfs1(v, u);
        }
    }

    void dfs2(int u, int p){
        for(auto it : adj[u]) {
            int v = it.first;
            int cost = it.second;

            if(v == p) continue;

            if(cost == 0)
                ans[v] = ans[u] + 1;
            else
                ans[v] = ans[u] - 1;

            dfs2(v, u);
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        ans.assign(n, 0);

        for(auto &e : edges){
            int u = e[0], v = e[1];

            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }

        dfs1(0, -1);
        dfs2(0, -1);

        return ans;
    }
};