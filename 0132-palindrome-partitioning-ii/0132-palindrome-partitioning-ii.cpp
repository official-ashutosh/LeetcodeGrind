class Solution {
public:

    vector<int> dp;
    vector<vector<int>> pal;

    bool check(string &s, int i, int j){
        if(i >= j) return true;

        if(pal[i][j] != -1) return pal[i][j];
        if(s[i] == s[j]){
            return pal[i][j] = check(s, i+1, j-1);
        }

        return pal[i][j] = 0;
    }

    int func(int i, string &s){
        if(i == s.size()) return -1;

        if(dp[i] != -1) return dp[i];
        int ans = s.size();

        for(int j=i; j<s.size(); j++){
            if(check(s, i, j)){
                ans = min(ans, func(j+1, s)+1);
            }
        }

        return dp[i] = ans;
    }

    int minCut(string s) {
        int n = s.size();
        dp.assign(n+1, -1);
        pal.assign(n+1, vector<int>(n+1, -1));

        return func(0, s);
    }
};