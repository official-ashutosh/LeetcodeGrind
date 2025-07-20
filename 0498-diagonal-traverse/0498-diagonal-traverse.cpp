class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;

        int n = mat.size();
        int m = mat[0].size();

        for(int i=0; i<=(m-1+n-1); i++){

            if(i % 2){
                for(int j=0; j<min(i+1, n); j++){
                    if(j < n && (i-j < m))
                    ans.push_back(mat[j][i-j]);
                }
            } else {
                for(int j=min(n-1, i); j>=0; j--){
                    if(j < n && (i-j < m))
                    ans.push_back(mat[j][i-j]);
                }
            }
        }

        return ans;

    }
};