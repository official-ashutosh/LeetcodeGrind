class Solution {
public:
    int countSquares(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        int ans = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(a[i][j] == 1 && i > 0 && j > 0) {
                    a[i][j] = 1 + min({a[i-1][j], a[i][j-1], a[i-1][j-1]});
                }
                ans += a[i][j];
            }
        }

        return ans;
    }
};
