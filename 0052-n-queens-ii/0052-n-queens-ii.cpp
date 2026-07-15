class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<int> cols(n, 0);
        vector<int> diag1(2*n-1, 0); 
        vector<int> diag2(2*n-1, 0); 
        
        func(0, n, ans, cols, diag1, diag2);
        return ans;
    }
    
private:
    void func(int row, int n, int& ans, vector<int>& cols, vector<int>& diag1, vector<int>& diag2) {
        
        if(row == n){
            ans++;
            return;
        }
        
        for(int j=0; j<n; j++){
            int d1 = row + j;
            int d2 = row - j+n-1;
            
            if(cols[j] || diag1[d1] || diag2[d2]) continue;
            
            cols[j] = 1;
            diag1[d1] = 1;
            diag2[d2] = 1;
            
            func(row + 1, n, ans, cols, diag1, diag2);
            
            cols[j] = 0;
            diag1[d1] = 0;
            diag2[d2] = 0;
        }
    }
};