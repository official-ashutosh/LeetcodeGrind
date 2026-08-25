class Solution {
public:
    vector<int> state;
    vector<int> ans;
    vector<int> path;

    void dfs(int u, vector<int> &edges) {
        state[u] = 1;
        path.push_back(u);

        int v = edges[u];

        if(state[v] == 0){
            dfs(v, edges);
        }
        else if(state[v] == 1) {   // cycle
            int len = 1;

            for(int i=path.size()-1; path[i]!=v; i--) {
                len++;
            }

            for(int i=path.size()-1; path[i] != v; i--){
                ans[path[i]] = len;
            }

            ans[v] = len;
        }

        // If u is not part of the cycle
        if(ans[u] == 0){
            ans[u] = 1 + ans[v];
        }

        state[u] = 2;
        path.pop_back();
    }

    vector<int> countVisitedNodes(vector<int>& edges) {

        int n = edges.size();

        state.assign(n, 0);
        ans.assign(n, 0);

        for(int i=0; i<n; i++){
            if(state[i] == 0) dfs(i, edges);
        }

        return ans;
    }
};