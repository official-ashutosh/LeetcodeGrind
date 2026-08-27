class Solution {
public:
    vector<pair<int, int>> dirs = {
        {1, 1}, {1, -1}, {-1, -1}, {-1, 1}
    };

    int m, n;
    int dp[510][510][5][2];
    vector<vector<int>> grid;

    int func(int cx, int cy, int d, int fl, int tar) {
        int nx = cx + dirs[d].first;
        int ny = cy + dirs[d].second;

        if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != tar){
            return 0;
        }

        if(dp[nx][ny][d][fl] != -1) return dp[nx][ny][d][fl];

        int ans = func(nx, ny, d, fl, 2-tar);

        if(fl){
            ans = max(ans, func(nx, ny, (d+1) % 4, 0, 2-tar));
        }

        return dp[nx][ny][d][fl] = ans + 1;
    }

    int lenOfVDiagonal(vector<vector<int>>& g) {
        grid = g;
        m = grid.size();
        n = grid[0].size();

        memset(dp, -1, sizeof(dp));

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < 4; d++) {
                        ans = max(ans, func(i, j, d, 1, 2) + 1);
                    }
                }
            }
        }

        return ans;
    }
};