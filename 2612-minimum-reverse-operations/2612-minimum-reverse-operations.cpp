class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<int> ans(n, -1);
        set<int> s2, s1;

        for(int i=0; i<n; i++){
            if(i % 2) s1.insert(i);
            else s2.insert(i);
        }

        for(auto i : banned){
            if(i % 2) s1.erase(i);
            else s2.erase(i);
        }

        if(p % 2) s1.erase(p);
        else s2.erase(p);

        queue<int> q;
        q.push(p);
        ans[p] = 0;

        while(!q.empty()){
            auto x = q.front();
            q.pop();

            int l = max(0, x-k+1);
            int r = min(x, n-k);
            int a = 2*l + k-1-x;
            int b = 2*r + k-1-x;

            if(a & 1){
                auto it = s1.lower_bound(a);
                while(it != s1.end() && *it <= b) {
                    int y = *it;
                    ans[y] = ans[x] + 1;
                    q.push(y);
                    it = s1.erase(it);
                }
            } else {
                auto it = s2.lower_bound(a);
                while(it != s2.end() && *it <= b) {
                    int y = *it;
                    ans[y] = ans[x] + 1;
                    q.push(y);
                    it = s2.erase(it);
                }
            }
        }

        return ans;
    }
};