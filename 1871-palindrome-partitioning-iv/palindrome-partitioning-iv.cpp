class Solution {
public:

    vector<vector<int>> dp;
    vector<vector<int>> pal;

    bool check(string &s, int i, int j){
        if(i >= j) return true;

        if(pal[i][j] != -1) return pal[i][j];
        if(s[i] == s[j]){
            return pal[i][j] = check(s, i+1, j-1);
        }

        return pal[i][j] = 0;
    }

    int func(int i, int ct, string &s){
        if(ct == 0) return (i == s.size());
        if(i == s.size()) return 0;

        if(dp[i][ct] != -1) return dp[i][ct];
        int ans = 0;

        for(int j=i; j<s.size(); j++){
            if(check(s, i, j)){
                ans |= func(j+1, ct-1, s);
            }
        }

        return dp[i][ct] = ans;
    }

    bool checkPartitioning(string s) {
        int n = s.size();
        dp.assign(n+1, vector<int>(4,-1));
        pal.assign(n+1, vector<int>(n+1, -1));

        return func(0, 3, s);
    }
};