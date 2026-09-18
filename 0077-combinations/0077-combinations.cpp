class Solution {
public:
    vector<vector<int>> ans;

    void solve(int id, int n, int k, vector<int>& cr) {
        if(cr.size() == k) {
            ans.push_back(cr);
            return;
        }

        for(int i=id; i<=n; i++){
            cr.push_back(i);
            solve(i+1, n, k, cr);
            cr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> cr;
        solve(1, n, k, cr);
        return ans;
    }
};