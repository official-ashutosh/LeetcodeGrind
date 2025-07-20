class Solution {
public:
    int maxConsecutiveAnswers(string a, int k) {
        int ct1 = 0, ct2 = 0;

        int n = a.size();
        int l = 0, r= 0;

        int ans = 1;
        while(r < n){
            if(a[r] == 'T') ct1++;
            else ct2++;

            while(min(ct1, ct2) > k){
                if(a[l] == 'T') ct1--;
                else ct2--;
                l++;
            }

            ans = max(ans, r-l+1);
            r++;
        }

        return ans;
    }
};