class Solution {
public:
    vector<int> ans;
    vector<bool> used;

    bool backtrack(int cr, int n) {
        if(ans.size() == (1 << n)){
            return __builtin_popcount(ans.back() ^ ans[0]) == 1;
        }

        for(int i=0; i<n; i++){
            int nxt = cr ^ (1<<i);

            if(!used[nxt]){
                used[nxt] = true;
                ans.push_back(nxt);

                if(backtrack(nxt, n)) return true;

                ans.pop_back();
                used[nxt] = false;
            }
        }

        return false;
    }

    vector<int> grayCode(int n) {
        int m = 1 << n;

        used.assign(m, false);
        ans.push_back(0);
        used[0] = true;

        backtrack(0, n);

        return ans;
    }
};