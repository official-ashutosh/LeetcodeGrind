class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int m = nums.size();
        int L = nums[0].size();
        
        vector<vector<int>> v(L + 1, vector<int>(m));
        for(int trim=1; trim<=L; ++trim) {
            // initialize indices 0..m-1
            for(int i=0; i<m; ++i) 
                v[trim][i] = i;
            
            // sort by trimmed suffix, then by index
            sort(v[trim].begin(), v[trim].end(),
                 [&](int a, int b) {
                     // compare last 'trim' chars
                     const string &A = nums[a], &B = nums[b];
                     int start = L - trim;
                     for (int k = start; k < L; ++k) {
                         if (A[k] != B[k]) 
                             return A[k] < B[k];
                     }
                     return a < b;
                 });
        }
        
        vector<int> ans;
        for(auto &q : queries) {
            int k = q[0], trim = q[1];
            ans.push_back(v[trim][k - 1]);
        }
        return ans;
    }
};
