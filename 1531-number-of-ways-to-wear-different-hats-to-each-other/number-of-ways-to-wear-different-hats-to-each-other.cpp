class Solution {
public:
    const long MOD = 1e9 + 7;
    
    long count(int hat, unordered_map<int, vector<int>>& p, int people, vector<vector<long>>& dp) {
        if (people == dp.size()-1) return 1;
        if (hat > 40) return 0;
        if (dp[people][hat] != -1) return dp[people][hat];
        
        long res = count(hat+1, p, people, dp);
        
        for (auto person: p[hat]) if ((people & 1<<person) == 0) {
            int more = people | 1<<person;
            res = (res + count(hat+1, p, more, dp)) % MOD;
        }
        
        return dp[people][hat] = res;
    }
    
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size(); // number of people
        unordered_map<int, vector<int>> p;
        for (int person=0; person<n; person++) {
            for (auto& hat: hats[person]) {
                p[hat].push_back(person);
            }
        }
        vector<vector<long>> dp(1 << n, vector<long>(41, -1));
        int people = 0;
        long res = count(1, p, people, dp);
        return res;
    }
};