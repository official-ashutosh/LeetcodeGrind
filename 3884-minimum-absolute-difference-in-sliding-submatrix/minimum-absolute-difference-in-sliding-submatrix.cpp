class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& a, int k) {
        int n = a.size();
        int m = a[0].size();

        int n1 = n-k+1;
        int m1 = m-k+1;

        vector<vector<int>> ans(n-k+1, vector<int>(m-k+1, 0));
        
        for(int i=0; i<n-k+1; i++){
            for(int j=0; j<m-k+1; j++){
                vector<int> v;
                for(int l=i; l<i+k; l++){
                    for(int r=j; r<j+k; r++){
                        v.push_back(a[l][r]);
                    }
                }
            

            if(v.size() < 2) {
                ans[i][j] = 0;
                continue;
            }

            int mn = INT_MAX;

            sort(v.begin(), v.end());
            for(int l=0; l<v.size()-1; l++){
                if(v[l] == v[l+1]) continue;
                mn = min(v[l+1]-v[l], mn);
            }

             if(mn != INT_MAX) ans[i][j] = mn;
            }
        }

        return ans;
    }
};