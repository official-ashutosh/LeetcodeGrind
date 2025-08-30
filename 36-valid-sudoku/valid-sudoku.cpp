class Solution {
public:

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

    bool isValidSudoku(vector<vector<char>>& a) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(a[i][j] != '.') {
                    char c = a[i][j];
                    a[i][j] = '.';
                    if(!isValid(a, i, j, c)) {
                        return false;
                    }
                    a[i][j] = c;
                }
            }
        }
        return true;
    }
};
