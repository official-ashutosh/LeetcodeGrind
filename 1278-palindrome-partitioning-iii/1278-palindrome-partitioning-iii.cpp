class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> pal;

    int cst(string &s, int i, int j){
        if(i >= j) return 0; 

        if(pal[i][j] != -1) return pal[i][j];
        
        return pal[i][j] = (s[i] != s[j]) + cst(s, i+1, j-1);
    }

    int func(int i, int ct, string &s){
        if(ct == 0){
            return (i == s.size()) ? 0 : 1e9;
        }
        
        if(i == s.size()) return 1e9;

        if(dp[i][ct] != -1) return dp[i][ct];
        
        int ans = 1e9; 
        
        for(int j=i; j<s.size(); j++){
            ans = min(ans, cst(s, i, j) + func(j+1, ct-1, s));
        }

        return dp[i][ct] = ans;
    }

    int palindromePartition(string s, int k) {
        int n = s.size();
        
        dp.assign(n+1, vector<int>(k+1, -1));
        pal.assign(n+1, vector<int>(n+1, -1));

        return func(0, k, s);
    }
};