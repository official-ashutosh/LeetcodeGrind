class Solution {
public:


    vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!grid[i][j]){
                    int fl = 1;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 1;

                    while(!q.empty()){
                        auto tp = q.front();
                        int x = tp.first;
                        int y = tp.second;

                        if(x == n-1 || y == m-1 || x == 0 || y == 0) fl = 0;

                        q.pop();
                        for(auto d : dir){
                            int nx = d.first + x;
                            int ny = d.second + y;
                            
                            if(nx >= 0 && ny >= 0 && nx < n && ny < m && !grid[nx][ny]){
                                grid[nx][ny] = 1;
                                q.push({nx, ny});
                            }
                        }
                    }

                    ans += fl;
                }
            }
        }

        return ans;
    }
};