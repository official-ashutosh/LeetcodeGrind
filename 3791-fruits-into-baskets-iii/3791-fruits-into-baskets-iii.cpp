class Solution {
public:
    int a[200010], sex[800010];

    void build(int node, int st, int en) {
        if(st == en) {
            sex[node] = a[st];
            return;
        }
        int mid = (st + en) / 2;
        build(2 * node, st, mid);
        build(2 * node + 1, mid + 1, en);
        sex[node] = max(sex[2 * node], sex[2 * node + 1]);
    }
    
    void update(int node, int st, int en, int idx, int val) {
        if(st == en) {
            a[st] = val;
            sex[node] = val;
            return;
        }
        int mid = (st + en) / 2;
        if(idx <= mid)
            update(2 * node, st, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, en, idx, val);
        sex[node] = max(sex[2 * node], sex[2 * node + 1]);
    }
    
    int query(int node, int st, int en, int x) {
        if(sex[node] < x) return -1;
        if(st == en) return st;
        int mid = (st + en) / 2;
        if(sex[2*node] >= x) return query(2 * node, st, mid, x);
        else return query(2 * node+1, mid+1, en, x);
    }
    
    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        int n = f.size();
        
        for(int i=0; i<n; i++) a[i] = b[i];
        build(1, 0, n-1);
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            int idx = query(1, 0, n-1, f[i]);
            if(idx == -1) ans++;
            else update(1, 0, n-1, idx, 0);
        }
        
        return ans;
    }
};
