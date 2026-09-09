class Solution {
public:
    int n, m;
    int ans = 0;
    int total = 0;

    vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

    void dfs(int x, int y, int count, vector<vector<int>>& grid) {

        if(grid[x][y] == 2){
            if(count == total)
                ans++;
            return;
        }

        grid[x][y] = -1;

        for(auto i : dir){
            int nx = x + i.first;
            int ny = y + i.second;

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != -1){
                dfs(nx, ny, count + 1, grid);
            }
        }

        grid[x][y] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int sx, sy;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] != -1) total++;

                if(grid[i][j] == 1){
                    sx = i;
                    sy = j;
                }
            }
        }

        dfs(sx, sy, 1, grid);

        return ans;
    }
};