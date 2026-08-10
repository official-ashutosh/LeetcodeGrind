class Solution {
public:  
    static int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        
        for(int i=0; i<m; i++){

            if(i > 0){
            for(int j=0;  j<n; j++){
                matrix[i][j]+=matrix[i][j]*matrix[i-1][j];
            }
            }
            const auto& row=matrix[i];
            int minH=i+1, maxH=0;
            for(int x: row){
                minH=min(minH, x);
                maxH=max(maxH, x);
            }
            vector<int> freq(maxH-minH+1, 0);
            for(int x: row){
                freq[x-minH]++;
            }
            int acc=0;
            for(int x=maxH-minH; acc<n; x--){
                if (freq[x]>0){
                    acc+=freq[x];
                    ans=max(ans, acc*(x+minH));
                }
            }  
        }
        return ans;
    }
};
