class Solution {
public:

    void dfs(int i, int j, vector<vector<int>> &heights, vector<vector<bool>> &ocean) {
        int n = heights.size();
        int m = heights[0].size();
        ocean[i][j] = true;
        
        vector<int> dirs = {0, 1, 0, -1, 0};  
        for(int d=0; d<4; d++) {
            int ni = i + dirs[d];
            int nj = j + dirs[d+1];
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && !ocean[ni][nj] && heights[ni][nj] >= heights[i][j]) {
                dfs(ni, nj, heights, ocean);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        
        for(int i=0; i<n; i++) {
            dfs(i, 0, heights, pacific); 
            dfs(i, m-1, heights, atlantic);  
        }
        
        for(int j=0; j<m; j++) {
            dfs(0, j, heights, pacific);
            dfs(n-1, j, heights, atlantic); 
        }
        
        vector<vector<int>> result;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
};
