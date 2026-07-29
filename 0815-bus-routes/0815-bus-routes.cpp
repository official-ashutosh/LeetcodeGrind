class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;

        unordered_map<int, vector<int>> g;
        int n = routes.size();

        for(int i=0; i<n; i++) {
            for(auto j : routes[i]) {
                g[j].push_back(i);
            }
        }

        queue<int> q;
        unordered_set<int> vis;
        unordered_map<int, int> dist;

        for(auto i : g[source]) {
            q.push(i);
            vis.insert(i);
            dist[i] = 1;
        }

        while(!q.empty()) {
            auto tp = q.front();
            q.pop();

            for(auto i : routes[tp]) {
                if(i == target) return dist[tp];

                for(auto child : g[i]) {
                    if(!vis.count(child)) {
                        vis.insert(child);
                        q.push(child);
                        dist[child] = dist[tp] + 1;
                    }
                }
            }
        }

        return -1;
    }
};