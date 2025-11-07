class Solution {
public:

    static const int N = 1e5+7;
    long long a[N], sex[4*N];

    void build(int node, int st, int en) {
        if (st == en) {
            sex[node] = a[st];
            return;
        }
        int mid = (st + en) / 2;
        build(2 * node, st, mid);
        build(2 * node + 1, mid + 1, en);
        sex[node] = (sex[2 * node]+ sex[2 * node + 1]);
    }

    long long query(int node, int st, int en, int l, int r) {
        if (st > r || l > en) return 0;
        if (st >= l && en <= r) return sex[node];
        int mid = (st + en) / 2;
        long long q1 = query(2 * node, st, mid, l, r);
        long long q2 = query(2 * node + 1, mid + 1, en, l, r);
        return (q1 + q2);
    }

    void update(int node, int st, int en, int idx, long long val) {
        if (st == en) {
            a[st] = val;
            sex[node] = val;
            return;
        }
        int mid = (st + en) / 2;
        if (idx <= mid) update(2 * node, st, mid, idx, val);
        else update(2 * node + 1, mid + 1, en, idx, val);
        sex[node] = (sex[2 * node] + sex[2 * node + 1]);
    }

    long long maxPower(vector<int>& stations, int mx, int k) {
        long long l = 0, r = 1e15, ans = 0;
        int n = stations.size();

        while(l <= r){
            long long mid = (r-l)/2 + l;

            vector<int> b = stations;
            long long ct = 0;
            for(int i=0; i<n; i++) a[i] = b[i];
            build(1, 0, n-1);


            for(int i=0; i<n; i++){
                int le = max(0, i - mx);
                int ri = min(n - 1, i + mx);
                long long sum = query(1, 0, n-1, le, ri);
                if(sum < mid){
                    long long add = mid - sum;
                    ct += add;
                    if(ct > k) break;
                    b[ri] += add;
                    update(1, 0, n-1, ri, a[ri] + add);
                }
            }

            if(ct <= k){
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }

        return ans;
    }
};
