class Solution {
public:

    bool dfs(int vertex, int color, vector<int> &colors, vector<vector<int>> &g) {
        colors[vertex] = color;
        for(auto child : g[vertex]) {
            if(colors[child] == -1) { // Unvisited
                if(!dfs(child, 1 - color, colors, g)) {
                    return false;
                }
            } else if(colors[child] == color) { // Same color on both sides
                return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> g(n+1);

        for(auto i : dislikes){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }

        vector<int> col(n+1, -1);

        for(int i=1; i<=n; i++){
            if(col[i] == -1){
                if(!dfs(i, 0, col, g)) return false;
            }
        }
        return true;
    }
};