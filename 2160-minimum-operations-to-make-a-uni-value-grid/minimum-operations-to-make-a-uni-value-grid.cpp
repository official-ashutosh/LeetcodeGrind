class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();

        int l = grid[0][0] % x;
        int sum = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] % x != l) return -1;
                sum += grid[i][j];
            }
        }

        int ans = INT_MAX;
        vector<int> v;
        for(auto i : grid){
            for(auto j : i) v.push_back(j);
        }

        sort(v.begin(), v.end());
        int sum1 = 0;
        for(int i=0; i<m*n; i++){
            int sum2 = sum - sum1 - v[i];
            int l = i;
            int r = m*n - i - 1;
            ans = min(ans, (v[i]*l-sum1)/(x) + (sum2-v[i]*r)/(x));
            // cout << sum1 << " " << sum2 << endl;
            // cout << l << " " << r << endl;
            sum1 += v[i];
            // cout << ans << endl;

        }


        return ans;


    }
};