 class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int mn1 = INT_MAX, mn2 = INT_MAX;
        int id1 = -1, id2 = -1;

        for (int j = 0; j < m; j++) {
            if (grid[0][j] <= mn1) {
                mn2 = mn1;
                id2 = id1;
                mn1 = grid[0][j];
                id1 = j;
            } else if (grid[0][j] < mn2) {
                mn2 = grid[0][j];
                id2 = j;
            }
        }

        for (int i = 1; i < n; i++) {
            int cur1 = INT_MAX, cur2 = INT_MAX;
            int cid1 = -1, cid2 = -1;

            for (int j = 0; j < m; j++) {
                int val = grid[i][j] + (j == id1 ? mn2 : mn1);

                if (val <= cur1) {
                    cur2 = cur1;
                    cid2 = cid1;
                    cur1 = val;
                    cid1 = j;
                } else if (val < cur2) {
                    cur2 = val;
                    cid2 = j;
                }
            }

            mn1 = cur1;
            mn2 = cur2;
            id1 = cid1;
            id2 = cid2;
        }

        return mn1;
    }
};