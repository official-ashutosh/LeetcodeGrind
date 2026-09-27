class Solution {
public:
    int numSubmatrixSumTarget(std::vector<std::vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0; i<m; i++){
            for(int j=1; j<n; j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }

        int ans = 0;
        for(int c1=0; c1<n; c1++){
            for(int c2=c1; c2<n; c2++){
                unordered_map<int, int> mp;
                mp[0] = 1;
                int sum = 0;

                for(int i=0; i<m; i++){
                    sum += matrix[i][c2] - (c1 > 0 ? matrix[i][c1-1] : 0);
                    ans += mp[sum-target];
                    mp[sum]++;
                }
            }
        }

        return ans;
    }
};



