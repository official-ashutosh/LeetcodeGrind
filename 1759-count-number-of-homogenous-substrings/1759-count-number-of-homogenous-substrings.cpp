class Solution {
public:

    const int mod = 1e9+7;
    int countHomogenous(string s) {
        long ans = 0;
        int  n = s.size();
        for(int i=0; i<n; i++){
            int ct = 1;
            while(i+1 < n && s[i+1] == s[i]){
                ct++;
                i++;
            }

            ans = (ans + (ct*(1ll)*(ct+1))/2) % mod;
        }

        return (int)ans;
    }
};