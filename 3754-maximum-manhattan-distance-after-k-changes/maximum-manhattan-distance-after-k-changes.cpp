class Solution {
public:
    int maxDistance(string si, int k) {
        int n = 0, w = 0, e = 0, s = 0;
        for(auto i : si){
            if(i == 'N') n++;
            else if(i == 'S') s++;
            else if(i == 'W') w++;
            else e++;
        }

        int ans = abs(n-s) + abs(e-w);
        int ans2 = 0;
        n = 0, w = 0, e = 0, s = 0;
        for(int i=0; i<si.length(); i++){
            if(si[i] == 'N') n++;
            else if(si[i] == 'S') s++;
            else if(si[i] == 'W') w++;
            else e++;

            ans2 = abs(n-s) + abs(e-w);
            int mn1 = min(n, s);
            int mn2 = min(e, w);
            int p = k;
            if(k >= mn1) {
                ans2 += 2*mn1;
                k -= mn1;
            } else {
                ans2 += 2*k;
                k = 0;
            }

            if(k >= mn2) {
                ans2 += 2*mn2;
                k -= mn2;
            } else {
                ans2 += 2*k;
                k = 0;
            }

            if(k > 0) ans2 += k;
            k = p;
            ans = max(ans, ans2);
        }

        int c = si.length();
        return min(c, ans);
    }
};