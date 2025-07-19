class Solution {
public:

    int dp[1010][1010];

    int func(int id, int left, vector<int> &a){
        if(id >= a.size()) return a[left];
        if(id == a.size()-1) return max(a[left], a.back());

        if(dp[id][left] != -1) return dp[id][left];

        int ans = INT_MAX;
        if(id < a.size()-1) ans = min(ans, func(id+2, left, a)+ max(a[id], a[id+1]));
        if(id < a.size()-1) ans = min(ans, func(id+2, id, a)+ max(a[left], a[id+1]));
        if(id < a.size()-1) ans = min(ans, func(id+2, id+1, a)+ max(a[left], a[id]));
        // cout << id << " " << ans << endl;

        return dp[id][left] = ans;
    }

    int minCost(vector<int>& a) {

        int mx = 0;
        for(auto i : a) mx = max(i, mx);
        if(a.size() < 3) return mx; 

        memset(dp, -1, sizeof(dp));
        int ans = func(3, 0, a)+max(a[1],a[2]);
        ans = min(ans, func(3, 1, a)+max(a[0],a[2]));
        ans = min(ans, func(3, 2, a)+max(a[1],a[0]));
        return ans;
    }
};