class Solution {
public:

    static const int N = 1e5+7;
    static const int MOD = 1e9+7;
    int a[N], sex[4*N];
    
    void build(int node, int st, int en) {
        if (st == en) {
            sex[node] = a[st];
            return;
        }
        int mid = (st + en) / 2;
        build(2 * node, st, mid);
        build(2 * node + 1, mid + 1, en);
        sex[node] = (sex[2 * node] + sex[2 * node + 1]) % MOD;
    }
    
    int query(int node, int st, int en, int l, int r) {
        if (st > r || l > en) return 0;
        if (st >= l && en <= r) return sex[node];
        int mid = (st + en) / 2;
        int q1 = query(2 * node, st, mid, l, r);
        int q2 = query(2 * node + 1, mid + 1, en, l, r);
        return (q1 + q2) % MOD;
    }
    
    void update(int node, int st, int en, int idx, int val) {
        if (st == en) {
            a[st] = (a[st] + val) % MOD;
            sex[node] = a[st];
            return;
        }
        int mid = (st + en) / 2;
        if (idx <= mid) update(2 * node, st, mid, idx, val);
        else update(2 * node + 1, mid + 1, en, idx, val);
        sex[node] = (sex[2 * node] + sex[2 * node + 1]) % MOD;
    }
    
    int countPermutations(vector<int>& c) {
        int n = c.size();
        set<int> s;
        for(auto i : c) s.insert(i);

        vector<int> vv;
        for(auto i : s) vv.push_back(i);

        int mx = s.size();
        // for(int i=0; i<=4*mx; i++) {
        //     a[i] = 0;
        //     sex[i] = 0;
        // }

        // long long ans  = 1;
        // int id = lower_bound(vv.begin(), vv.end(),c[0])-vv.begin()+1;

        // build(1, 1, mx);
        // update(1, 1, mx, id, 1);

        // for(int i=1; i<n; i++){
        //     id = lower_bound(vv.begin(), vv.end(),c[i])-vv.begin()+1;

        //     long long ans2 = query(1, 1, mx, 1, id-1);
        //     if(ans2 == 0) return 0;
        //     cout << ans2 << " " << id << endl;
        //     ans = (ans*ans2) % MOD;
        //     update(1, 1, mx, id, 1);
        // }

        // if(mx != n) return 0;
        int mn = c[0];
        for(int i=1; i<n; i++){
            if(c[i] <= mn) return 0;
            mn = min(mn, c[i]);
        }

        cout << mn << endl;
        long long ans = 1;
        for(int i=2; i<n; i++){
            ans = (ans*i) % MOD;
        }

        return ans;
        
    }
};