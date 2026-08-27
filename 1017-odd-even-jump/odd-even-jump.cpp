class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();

        vector<pair<int,int>> v;
        for(int i=0; i<n; i++)
            v.push_back({arr[i], i});

        sort(v.begin(), v.end());

        vector<int> odd(n, -1), even(n, -1);
        set<pair<int,int>> st;

        for(int i=n-1; i>=0; i--){
            auto it = st.lower_bound({arr[i], -1});
            if(it != st.end())
                odd[i] = it->second;

            st.insert({arr[i], i});
        }

        st.clear();

        for(int i=n-1; i>=0; i--){
            auto it = st.upper_bound({arr[i], INT_MAX});
            if(it != st.begin()){
                it--;
                int val = it->first;

                it = st.lower_bound({val, i+1});
                even[i] = it->second;
            }

            st.insert({arr[i], i});
        }

        vector<int> goodOdd(n, 0), goodEven(n, 0);
        goodOdd[n-1] = goodEven[n-1] = 1;

        for(int i=n-2; i>=0; i--){
            if(odd[i] != -1)
                goodOdd[i] = goodEven[odd[i]];

            if(even[i] != -1)
                goodEven[i] = goodOdd[even[i]];
        }

        int ans = 0;
        for(int i=0; i<n; i++)
            ans += goodOdd[i];

        return ans;
    }
};