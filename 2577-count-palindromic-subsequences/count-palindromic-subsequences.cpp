class Solution {
public:

    int dp[10010][6][11][11];

    static const int mod = 1e9+7;

    bool pal(string &s){
        for(int i=0; i<2; i++){
            if(s[i] != s[4-i]) return false;
        }

        return true;
    }

    int func(int id, int p, int f, int se, string &s){

        if(p == 5) return 1;
        if(id == s.size()){
            return 0;
        }

        if(p > 5) return 0;

        if(dp[id][p][f+1][se+1] != -1) return dp[id][p][f+1][se+1];

        int ans = 0;
        ans = (ans+func(id+1, p, f, se, s))  % mod;
        if(f == -1) ans = (ans + func(id+1, p+1, s[id]-'0', se, s)) % mod;
        else if(se == -1) ans = (ans + func(id+1, p+1, f, s[id]-'0', s)) % mod;
        else {
            if(p == 2 || (p == 3 && s[id]-'0' == se) || (p == 4  && s[id]-'0' == f)) ans = (ans + func(id+1, p+1, f, se, s)) % mod;
        }

        return dp[id][p][f+1][se+1] = ans;

    }

    int countPalindromes(string s) {
        memset(dp, -1, sizeof(dp));

        return func(0, 0, -1, -1, s);
    }
};