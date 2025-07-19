class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> right(n+2);

        for(int i=0; i<=n; i++){
            int l = max(0, i-ranges[i]);
            int r = min(n, i+ranges[i]);

            right[l] = max(right[l], r);
        }

        int ans = 0;
        int r = 0, i = 0;
        while(r < n && i <= n){
            int mx = r;
            while(i <= r){
                mx = max(mx, right[i]);
                i++;
            }

            if(mx == r) return -1;
            r = mx;
            ans++;
        }

        return ans;
    }
};
