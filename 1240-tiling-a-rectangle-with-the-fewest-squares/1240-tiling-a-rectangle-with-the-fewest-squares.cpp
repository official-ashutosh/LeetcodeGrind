class Solution {
public:
    int ans = 169;

    void func(vector<int>& h, int n, int m, int cnt) {
        if (cnt >= ans) return;

        int pos = 0;
        for(int i=1; i<m; i++){
            if(h[i] < h[pos])
                pos = i;
        }

        if(h[pos] == n){
            ans = min(ans, cnt);
            return;
        }

        int width = 0;

        while(pos + width < m &&
               h[pos + width] == h[pos]) {
            width++;
        }

        // Largest square that can be placed here
        int mx = min(width, n - h[pos]);

        // Try larger squares first
        for(int sz = mx; sz >= 1; sz--) {
            for(int j=0; j<sz; j++){
                h[pos+j] += sz;
            }

            func(h, n, m, cnt+1);

            for(int j=0; j<sz; j++){
                h[pos + j] -= sz;
            }
        }
    }

    int tilingRectangle(int n, int m) {
        if(n == m) return 1;

        vector<int> h(m, 0);

        func(h, n, m, 0);

        return ans;
    }
};