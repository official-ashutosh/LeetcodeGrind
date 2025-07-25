class Solution {
public:

    int func(int id, string &s, vector<int> &dp) {
        if(id == s.size()) return 1;

        if(dp[id] != -1) return dp[id];

        if(s[id]=='0') return 0;

        int ans = func(id+1, s, dp);

        if(id<s.size()-1 && (s[id]=='1'||s[id]=='2'&&s[id+1]<'7')) ans+=func(id+2, s, dp);

        return dp[id] = ans;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,-1);

        return s.empty()? 0 : func(0,s,dp);   
    }
};