class Solution {
public:

    int maximalRectangle(vector<vector<char>>& a) {
        int n = a.size();
        int m = a[0].size();

        vector<int> le(m, 0), ri(m, m), hi(m, 0);
        int ans = 0;
        for(int i=0; i<n; i++){
            int cl = 0, cr = m;

            for(int j=0; j<m; j++){
                if(a[i][j] == '1') {
                    hi[j]++;
                    le[j] = max(le[j], cl);
                }
                else {
                    hi[j] = 0;
                    le[j] = 0;
                    cl = j+1;
                }
            }

            for(int j=m-1; j>=0; j--){
                if(a[i][j] == '1'){
                    ri[j] = min(ri[j], cr);
                } else {
                    ri[j] = m;
                    cr = j;
                }
            }

            for(int j=0; j<m; j++){
                ans = max(ans, (ri[j]-le[j])*hi[j]);
            }
        }

        return ans;
    }
};