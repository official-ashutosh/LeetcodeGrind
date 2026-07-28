class Solution {
public:
    struct BIT {
        int n;
        vector<int> bit;

        BIT(int n) : n(n), bit(n + 1, 0) {}

        void update(int idx, int val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        int query(int idx) {
            int res = 0;
            while (idx > 0) {
                res += bit[idx];
                idx -= idx & -idx;
            }
            return res;
        }
    };

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();

        vector<int> vals;
        vector<int> a(n);

        for(int i=0; i<n; i++){
            a[i] = nums1[i]-nums2[i];
            vals.push_back(a[i]);
            vals.push_back(a[i] + diff);
        }

        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        BIT bit(vals.size());

        long long ans = 0;

        for(int i=0; i<n; i++) {
            int pos = upper_bound(vals.begin(), vals.end(), a[i]+diff) - vals.begin();
            ans += bit.query(pos);

            int idx = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1;
            bit.update(idx, 1);
        }

        return ans;
    }
};