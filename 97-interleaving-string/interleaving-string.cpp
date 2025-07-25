class Solution {
public:
    string s1, s2, s3;
    int m, n;
    vector<vector<int>> memo; // -1 = unvisited, 0 = false, 1 = true

    bool dfs(int i, int j, int k) {
        if (k == s3.size()) return true;
        int &res = memo[i][j];
        if (res != -1) return res;
        
        bool ok = false;
        if (i < m && s1[i] == s3[k]) {
            ok = dfs(i+1, j, k+1);
        }
        if (!ok && j < n && s2[j] == s3[k]) {
            ok = dfs(i, j+1, k+1);
        }
        return res = ok;
    }

    bool isInterleave(string _s1, string _s2, string _s3) {
        s1 = _s1; s2 = _s2; s3 = _s3;
        m = s1.size(); n = s2.size();
        if (m + n != s3.size()) return false;
        memo.assign(m+1, vector<int>(n+1, -1));
        return dfs(0, 0, 0);
    }
};
