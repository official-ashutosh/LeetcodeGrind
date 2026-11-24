class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();

        vector<set<int>> g(n+1);
        for(auto i : edges){
            g[i[0]].insert(i[1]);
            g[i[1]].insert(i[0]);
        }

        queue<int> lvs;
        for(int i=0; i<n; i++){
            if(g[i].size() == 1 && !coins[i]) lvs.push(i);

        }

        int del = 0;
        while(!lvs.empty()){
            auto it = lvs.front();
            lvs.pop();

            if(g[it].empty()) continue;

            int par = *g[it].begin();
            g[par].erase(it);
            g[it].erase(par);
            del += 2;

            if(g[par].size() == 1 && !coins[par]) lvs.push(par);
        }

        for(int i=0; i<n; i++){
            if(g[i].size() == 1) lvs.push(i);
        }

        for(int i=0; i<2; i++){
            int sz = lvs.size();
            while(sz--){
                auto it = lvs.front();
                lvs.pop();

                if(g[it].empty()) continue;

                int par = *g[it].begin();

                g[par].erase(it);
                g[it].erase(par);

                del+=2;

                if(g[par].size() == 1) lvs.push(par);
            }
        }

        int ans = 2*(n-1) - del;
        return ans;
    }
};