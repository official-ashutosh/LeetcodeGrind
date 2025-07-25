class Solution {
public:
    vector<int> adj[100010];  // adjacency list
    vector<int> subtreeXor;   // xor of subtree rooted at each node
    vector<int> parent;       // parent for each node
    int totalXor = 0;         // xor of the entire tree

    void dfs(int u, int p, vector<int>& nums) {
        subtreeXor[u] = nums[u];
        parent[u] = p;
        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, nums);
                subtreeXor[u] ^= subtreeXor[v];
            }
        }
    }

    bool isDescendant(int u, int v) {
        // Returns true if u is in the subtree of v
        while (u != -1) {
            if (u == v) return true;
            u = parent[u];
        }
        return false;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        subtreeXor.resize(n);
        parent.resize(n, -1);

        // Build tree
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // 1. Run DFS from node 0 to compute subtree XORs
        dfs(0, -1, nums);
        totalXor = subtreeXor[0];

        int ans = INT_MAX;

        // 2. Try every pair of edges (i, j)
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = i, b = j;

                // Ensure that we always treat a as lower in tree (child side)
                if (isDescendant(a, b)) {
                    int x = subtreeXor[a];
                    int y = subtreeXor[b] ^ subtreeXor[a];
                    int z = totalXor ^ subtreeXor[b];
                    ans = min(ans, max({x, y, z}) - min({x, y, z}));
                } else if (isDescendant(b, a)) {
                    int x = subtreeXor[b];
                    int y = subtreeXor[a] ^ subtreeXor[b];
                    int z = totalXor ^ subtreeXor[a];
                    ans = min(ans, max({x, y, z}) - min({x, y, z}));
                } else {
                    int x = subtreeXor[a];
                    int y = subtreeXor[b];
                    int z = totalXor ^ x ^ y;
                    ans = min(ans, max({x, y, z}) - min({x, y, z}));
                }
            }
        }

        return ans;
    }
};
