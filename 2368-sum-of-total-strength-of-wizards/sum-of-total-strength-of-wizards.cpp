class Solution {
public:

    vector<vector<int>> sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> le(n, 1);
        vector<int> ri(n, 1);

        stack<int> s;
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && arr[s.top()] > arr[i]) s.pop();

            if(!s.empty()) ri[i] = (s.top()-i);
            else ri[i] = (n-i); 

            s.push(i);
        }

        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop(); 

            if(!st.empty()) le[i] = (i-st.top());
            else le[i] = (i+1);

            st.push(i);
        }

        vector<vector<int>> ans;
        ans.push_back(le);
        ans.push_back(ri);

        return ans;
    }

    const int mod = 1e9+7;

    int totalStrength(vector<int>& s) {
        vector<vector<int>> v = sumSubarrayMins(s);
        vector<int> le = v[0];
        vector<int> ri = v[1];
        int n = s.size();

        vector<long long> pre(n+1, 0);

        for(int i=0; i<n; i++)
            pre[i+1] = (pre[i]+s[i]) % mod;

        vector<long long> prere(n+2, 0);

        for(int i=0; i<=n; i++)
            prere[i+1] = (prere[i]+pre[i]) % mod;

        long long ans = 0;

        for(int i=0; i<n; i++) {

            int l = i-le[i];
            int r = i+ri[i];

            long long sum2 = (prere[r+1]-prere[i+1] + mod) % mod;

            long long sum1 = (prere[i+1]-prere[l+1] + mod) % mod;

            long long ct = (sum2*le[i] % mod - sum1*ri[i] % mod + mod) % mod;

            ans = (ans + ct*s[i]) % mod;
        }

        return ans;

    }
};