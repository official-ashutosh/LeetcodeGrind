class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size();
        int ans = 0;

        for(int mask = 0; mask < (1 << m); mask++){
            vector<int> v(n, 0);
            int ans2 = 0;

            for(int i=0; i<m; i++){
                if(mask & (1 << i)){
                    v[requests[i][0]]--;
                    v[requests[i][1]]++;
                    ans2++;
                }
            }

            int fl = 1;

            for(int i : v){
                if(i){
                    fl = 0;
                    break;
                }
            }

            if(fl)
                ans = max(ans, ans2);
        }

        return ans;
    }
};