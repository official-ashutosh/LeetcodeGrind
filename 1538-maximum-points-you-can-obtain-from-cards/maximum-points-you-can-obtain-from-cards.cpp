class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int n = c.size();

        int ans = 0;
        for(int i=0; i<k; i++){
            ans += c[i]; 
        }

        int l = k-1;
        int r = n-1;

        int sum = ans;

        while(l >= 0){
            sum -= c[l];
            sum += c[r];
            ans = max(ans, sum);
            l--;
            r--;
        }

        return ans;
    }
};
