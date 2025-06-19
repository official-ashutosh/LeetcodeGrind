class Solution {
public:
    int totalFruit(vector<int>& f) {
        int p1 = f[0], p2 = -1;
        int ct1 = 1, ct2 = 0;
        int n = f.size();

        int l=0, r = 1, ans  = 1;
        int prev = f[0], ct = 1;

        while(r < n){
            if(f[r] == p1) ct1++;
            else if(f[r] == p2) ct2++;
            else if(p2 == -1) {
                p2 = f[r];
                ct2++;
            } else {

                l = r-ct;
                if(f[r-1] == p1){
                    p2 = f[r];
                    ct2 = 1;
                    ct1 = ct;
                    p1 = f[r-1];
                } else {
                    p1 = f[r];
                    ct1 = 1;
                    ct2 = ct;
                    p2 = f[r-1];
                }
            }

            if(f[r] == prev) ct++;
            else {
                prev = f[r];
                ct = 1;
            }

            ans = max(ans,ct1+ct2);
            r++;
        }

        return ans;
    }
};
