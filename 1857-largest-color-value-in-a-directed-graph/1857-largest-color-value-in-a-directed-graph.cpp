class Solution {
public:

    bool cycle(vector<int> deg, vector<vector<int>> &g) {
        int n = deg.size();

        queue<int> q;
        for(int i=0; i<n; i++){
            if(!deg[i]) q.push(i);
        }

        int ct = 0;

        while(!q.empty()) {
            int tp = q.front();
            q.pop();
            ct++;

            for(auto child : g[tp]){
                deg[child]--;

                if(deg[child] == 0) q.push(child);
            }
        }

        return ct == n;
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();

        vector<int> deg(n);
        vector<vector<int>> g(n);

        for(auto e : edges){
            g[e[0]].push_back(e[1]);
            deg[e[1]]++;
        }

        if(!cycle(deg, g)) return -1;

        queue<int> q;
        vector<vector<int>> dp(n, vector<int>(26, 0));

        for(int i=0; i<n; i++) {
            if(deg[i] == 0) {
                q.push(i);
                dp[i][colors[i]-'a'] = 1;
            }
        }

        int ans = 0;

        while(!q.empty()) {
            int tp = q.front();
            q.pop();

            ans = max(ans, dp[tp][colors[tp]-'a']);

            for(auto child : g[tp]){

                for(int i=0; i<26; i++){
                    dp[child][i] = max(dp[child][i], dp[tp][i]);
                }

                dp[child][colors[child]-'a'] = max(dp[child][colors[child]-'a'], 
                dp[tp][colors[child]-'a']+1);

                deg[child]--;

                if(deg[child] == 0) q.push(child);
            }
        }

        for(int i=0; i<n; i++){
            ans = max(ans, dp[i][colors[i] - 'a']);
        }

        return ans;
    }
};