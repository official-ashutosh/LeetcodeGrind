class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = (1 << n) - 1;

        queue<pair<int,int>> q;
        vector<vector<int>> dist(n, vector<int>(m+1, -1));

        for(int i=0; i<n; i++){
            q.push({i, 1 << i});
            dist[i][1 << i] = 0;
        }

        while(!q.empty()){
            auto [u, mask] = q.front();
            q.pop();

            if(mask == m)
                return dist[u][mask];

            for(auto v : graph[u]){
                int nMask = mask | (1 << v);

                if(dist[v][nMask] == -1){
                    dist[v][nMask] = dist[u][mask] + 1;
                    q.push({v, nMask});
                }
            }
        }

        return -1;
    }
};