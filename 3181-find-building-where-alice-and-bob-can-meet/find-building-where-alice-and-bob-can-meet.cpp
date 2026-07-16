class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& h,
                                        vector<vector<int>>& queries) {
        int n = h.size();

        vector<vector<pair<int,int>>> qs(n);
        vector<int> ans(queries.size(), -1);

        for(int i=0; i<queries.size(); i++) {
            int a = queries[i][0];
            int b = queries[i][1];

            if(a > b) swap(a, b);

            if(a == b || h[a] < h[b]) ans[i] = b;
            else qs[b].push_back({h[a], i});
        }

        vector<int> st; 

        for(int i=n-1; i>=0; i--) {

            while(!st.empty() && h[st.back()] <= h[i])
                st.pop_back();

            st.push_back(i);

            for(auto &[need, idx] : qs[i]){

                int l = 0, r = st.size()-1;
                int res = -1;

                while(l <= r) {
                    int mid = (l + r) / 2;

                    if(h[st[mid]] > need) {
                        res = st[mid];
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }

                ans[idx] = res;
            }
        }

        return ans;
    }
};