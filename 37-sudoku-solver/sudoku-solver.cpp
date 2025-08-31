class Solution {
public:

    bool solve(vector<vector<char>>& a) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(a[i][j] == '.') {
                    for(char c='1'; c<='9'; c++) {
                        if(isValid(a, i, j, c)) {
                            a[i][j] = c;
                            if(solve(a)) return true;
                            a[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true; 
    }
    
    bool isValid(vector<vector<char>>& a, int row, int col, char c) {
        for(int i=0; i<9; i++) {
            if(a[row][i] == c) return false;
            if(a[i][col] == c) return false;

            int l = 3 * (row / 3) + i / 3;
            int r = 3 * (col / 3) + i % 3;
            if(a[l][r] == c) return false;
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};