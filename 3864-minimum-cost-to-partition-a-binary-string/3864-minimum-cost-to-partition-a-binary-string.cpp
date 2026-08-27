class Solution {
public:
    vector<int> pre;
    string s;
    int encCost, flatCost;

    long long dfs(int l, int r) {
        int ones = pre[r] - pre[l];

        long long cost = (ones == 0)
            ? flatCost
            : 1LL * (r - l) * ones * encCost;

        if ((r - l) % 2 == 0) {
            int mid = (l + r) / 2;
            cost = min(cost, dfs(l, mid) + dfs(mid, r));
        }

        return cost;
    }

    long long minCost(string str, int ec, int fc) {
        s = str;
        encCost = ec;
        flatCost = fc;

        int n = s.size();
        pre.resize(n + 1);

        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + (s[i] - '0');

        return dfs(0, n);
    }
};