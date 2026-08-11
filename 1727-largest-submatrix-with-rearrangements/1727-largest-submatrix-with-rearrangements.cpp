class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> h(m);
        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]) h[j]++;
                else h[j] = 0;
            }

            vector<int> v = h;
            sort(v.rbegin(), v.rend());

            for(int j=0; j<m; j++)
                ans = max(ans, v[j]*(j+1));
        }

        return ans;
    }
};