class Solution {
public:

    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';  
                    
                    while(!q.empty()) {
                        auto tp = q.front();

                        int r = tp.first;
                        int c = tp.second;
                        q.pop();

                        for(auto& d : dirs) {
                            int rr = r + d.first, cc = c + d.second;
                            if(rr >= 0 && rr < m && cc >= 0 && cc < n && grid[rr][cc] == '1') {
                                grid[rr][cc] = '0';
                                q.push({rr, cc});
                            }
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};
