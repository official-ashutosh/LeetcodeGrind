class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {

        int n = targetGrid.size();
        int m = targetGrid[0].size();

        vector<vector<int>> v(61, vector<int>(4, 0));

        for (int i = 1; i < 61; i++) {
            v[i][0] = INT_MAX;
            v[i][1] = INT_MAX;
            v[i][2] = INT_MIN;
            v[i][3] = INT_MIN;
        }

        map<int, int> mp;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int col = targetGrid[i][j];
                mp[col]++;

                v[col][0] = min(v[col][0], i);
                v[col][1] = min(v[col][1], j);
                v[col][2] = max(v[col][2], i);
                v[col][3] = max(v[col][3], j);
            }
        }

        unordered_set<int> s;

        vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));

        while (s.size() < mp.size()) {

            bool found = false;

            for (int col = 1; col < 61; col++) {

                if (!mp.count(col) || s.count(col))
                    continue;

                vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {

                        int ri = 0;

                        if (targetGrid[i][j] != col &&
                            !s.count(targetGrid[i][j])) {
                            ri = 1;
                        }

                        pre[i + 1][j + 1] =
                            pre[i][j + 1] +
                            pre[i + 1][j] -
                            pre[i][j] +
                            ri;
                    }
                }

                int co = -1;

                auto cordd = v[col];

                int r1 = cordd[0];
                int c1 = cordd[1];
                int r2 = cordd[2];
                int c2 = cordd[3];

                int sum =
                    pre[r2 + 1][c2 + 1]
                    - pre[r1][c2 + 1]
                    - pre[r2 + 1][c1]
                    + pre[r1][c1];

                if (sum == 0) {
                    s.insert(col);
                    found = true;
                }
            }

            if (!found)
                return false;
        }

        return true;
    }
};