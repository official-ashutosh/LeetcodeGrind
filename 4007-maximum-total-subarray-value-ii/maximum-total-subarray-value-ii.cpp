class Solution {
public:
    struct SegTree {
        int n;
        vector<int> mx, mn;

        SegTree(vector<int>& nums) {
            n = nums.size();
            mx.assign(4 * n, 0);
            mn.assign(4 * n, 0);
            build(1, 0, n - 1, nums);
        }

        void build(int node, int l, int r, vector<int>& nums) {
            if(l == r) {
                mx[node] = mn[node] = nums[l];
                return;
            }
            int mid = (l + r) >> 1;
            build(node << 1, l, mid, nums);
            build(node << 1 | 1, mid + 1, r, nums);
            mx[node] = max(mx[node << 1], mx[node << 1 | 1]);
            mn[node] = min(mn[node << 1], mn[node << 1 | 1]);
        }

        int queryMax(int node, int l, int r, int ql, int qr) {
            if(ql <= l && r <= qr) return mx[node];
            int mid = (l + r) >> 1;
            int res = INT_MIN;
            if(ql <= mid) res = max(res, queryMax(node << 1, l, mid, ql, qr));
            if(qr > mid) res = max(res, queryMax(node << 1 | 1, mid + 1, r, ql, qr));
            return res;
        }

        int queryMin(int node, int l, int r, int ql, int qr) {
            if(ql <= l && r <= qr) return mn[node];
            int mid = (l + r) >> 1;
            int res = INT_MAX;
            if(ql <= mid) res = min(res, queryMin(node << 1, l, mid, ql, qr));
            if(qr > mid) res = min(res, queryMin(node << 1 | 1, mid + 1, r, ql, qr));
            return res;
        }
    };

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        SegTree st(nums);

        priority_queue<tuple<long long,int,int>> pq;

        for(int l = 0; l < n; l++) {
            long long val = (long long)st.queryMax(1, 0, n - 1, l, n - 1) - st.queryMin(1, 0, n - 1, l, n - 1);
            pq.push({val, l, n - 1});
        }

        long long ans = 0;
        while(k--) {
            auto [val, l, r] = pq.top();
            pq.pop();
            ans += val;

            if(r > l) {
                r--;
                long long nval = (long long)st.queryMax(1, 0, n - 1, l, r) - st.queryMin(1, 0, n - 1, l, r);
                pq.push({nval, l, r});
            }
        }

        return ans;
    }
};