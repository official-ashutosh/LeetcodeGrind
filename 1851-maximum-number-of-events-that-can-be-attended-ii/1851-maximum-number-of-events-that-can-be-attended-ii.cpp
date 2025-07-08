class Solution {
public:
    vector<vector<int>> dp;

    int nxxx(int en, vector<vector<int>>&a) {
        int l = 0, r = a.size();
        while(l < r) {
            int mid = (l+r)/2;
            if(a[mid][0] > en) r = mid;
            else l = mid+1;
        }
        return l;
    }

    int func(int id, int k, vector<vector<int>>&a) {
        if(k == 0 || id == a.size()) return 0;
        if(dp[id][k] != -1) return dp[id][k];

        int ans = func(id+1, k, a);

        int nxt = nxxx(a[id][1], a);
        ans = max(ans, a[id][2] + func(nxt, k-1, a));

        return dp[id][k] = ans;
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end()); 

        int n = events.size();
        dp.assign(n+1, vector<int>(k+1, -1));

        return func(0, k, events);
    }
};
