class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;

        vector<pair<int, int>> prev;

        for(int i=0; i<n; i++){
            vector<pair<int, int>> h;
            vector<int> seen(m, 0);

            for(auto j : prev){
                int hi = j.first;
                int c = j.second;
                if(matrix[i][c]){
                    h.push_back({hi+1, c});
                    seen[c] = 1;
                }
            }

            for(int j=0; j<m; j++){
                if(matrix[i][j] && !seen[j]){
                    h.push_back({1, j});
                }
            }

            for(int j=0; j<h.size(); j++)
                ans = max(ans, h[j].first*(j+1));
            
            prev = h;
        }

        return ans;
    }
};