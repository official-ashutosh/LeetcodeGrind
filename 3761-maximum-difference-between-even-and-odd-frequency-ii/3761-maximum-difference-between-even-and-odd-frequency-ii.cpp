class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size();

        vector<vector<int>> pre(n+1, vector<int>(5, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<=4; j++) pre[i+1][j] = pre[i][j];
            pre[i+1][s[i]-'0']++;
        }

        long ans = INT_MIN;
        for(int a=0; a<=4; a++){
            if(!pre[n][a]) continue;

            for(int b=0; b<=4; b++){
                if(a == b || !pre[n][b]) continue;

                vector<vector<long>> v(2, vector<long>(2, INT_MAX));
                long ct1 = 0, ct2 = 0, prev1 = 0, prev2 = 0;

                int l = 0, r = k-1;
                while(r < n){
                    ct1 = pre[r+1][a];
                    ct2 = pre[r+1][b];

                    while(r-l+1 >= k && ct2-prev2 >= 2){
                        int i = (prev1 & 1);
                        int j = (prev2 & 1);
                        v[i][j] = min(v[i][j], prev1-prev2);

                        prev1 = pre[l+1][a];
                        prev2 = pre[l+1][b];
                        l++;
                    }

                    int i = (ct1 % 2 == 0);
                    int j = (ct2 & 1);
                    ans = max(ans, (ct1-ct2-v[i][j]));
                    r++;
                }
            }
        }

        return ans;

    }
};