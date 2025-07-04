class NumArray {
private:
    vector<int> segTree;
    int n;

    void build(vector<int>& nums, int node, int l, int r) {
        if (l == r) {
            segTree[node] = nums[l];
        } else {
            int mid = (l + r) / 2;
            build(nums, 2 * node + 1, l, mid);
            build(nums, 2 * node + 2, mid + 1, r);
            segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
        }
    }

    void updateUtil(int node, int l, int r, int index, int val) {
        if (l == r) {
            segTree[node] = val;
        } else {
            int mid = (l + r) / 2;
            if (index <= mid)
                updateUtil(2 * node + 1, l, mid, index, val);
            else
                updateUtil(2 * node + 2, mid + 1, r, index, val);
            segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
        }
    }

    int sumRangeUtil(int node, int l, int r, int ql, int qr) {
        if(ql > r || qr < l)
            return 0;
        if(ql <= l && r <= qr)
            return segTree[node];
        int mid = (l+r) / 2;
        return sumRangeUtil(2*node + 1, l, mid, ql, qr) +
               sumRangeUtil(2*node + 2, mid + 1, r, ql, qr);
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4*n, 0);
        build(nums, 0, 0, n-1);
    }

    void update(int index, int val) {
        updateUtil(0, 0, n-1, index, val);
    }

    int sumRange(int left, int right) {
        return sumRangeUtil(0, 0, n-1, left, right);
    }
};
