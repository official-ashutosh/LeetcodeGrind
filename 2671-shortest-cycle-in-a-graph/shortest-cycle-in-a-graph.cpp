class Solution
{
public:
    
    int ans = INT_MAX;

    void bfs(int src, vector<int> g[], int n){
        vector<int> dist(n,1e9);
        vector<int> par(n, -1);
        
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto child : g[node]){
                if(dist[child] == 1e9){
                    dist[child] = 1 + dist[node];
                    par[child] = node;
                    q.push(child);
                }
                else if(par[node] != child && par[child] != node)
                    ans = min(ans, dist[child]+dist[node] + 1);
            }
        }
    }

    int findShortestCycle(int n, vector<vector<int>> &edges){

        vector<int> g[n+1];
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
      
        for(int i=0; i<n; i++){
            bfs(i,g,n);
        }

        if(ans == INT_MAX) return -1;
        return ans;
    }
};

