class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        deque<pair<int,int>> dq;

        dist[0][0] = 0;
        dq.push_front({0, 0});

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for(int d=0; d<4; d++){
                int nx = x + dx[d];
                int ny = y + dy[d];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                int cost = grid[x][y];

                if(dist[x][y] + cost < dist[nx][ny]){
                    dist[nx][ny] = dist[x][y] + cost;

                    if(cost == 0) dq.push_front({nx, ny});
                    else dq.push_back({nx, ny});
                }
            }
        }

        return dist[n-1][m-1];
    }
};