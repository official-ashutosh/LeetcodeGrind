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

    vector<vector<int>> sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> le(n, 1);
        vector<int> ri(n, 1);

        stack<int> s;
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && arr[s.top()] < arr[i]) s.pop();

            if(!s.empty()) ri[i] = (s.top()-i);
            else ri[i] = (n-i); 

            s.push(i);
        }

        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop(); 

            if(!st.empty()) le[i] = (i-st.top());
            else le[i] = (i+1);

            st.push(i);
        }

        vector<vector<int>> ans;
        ans.push_back(le);
        ans.push_back(ri);

        return ans;
    }

    long long calc(long long le, long long ri, long long k) {
        long long ans = 0;

        long long x = min(le, k);
        long long t = max(0LL, k-ri+1);

        if(x > 0){
            long long a = min(x, t);
            ans += a*ri;

            if(x > a) {
                long long l = a+1;
                long long r = x;
                ans += (r-l+1)*(k+1) - (l+r)*(r-l+1)/2;
            }
        }

        return ans;
    }

    long long minMaxSubarraySum(vector<int>& nums, int k) {
        vector<vector<int>> mx = sumSubarrayMaxs(nums);
        vector<vector<int>> mn = sumSubarrayMins(nums);

        int n = nums.size();
        long long ans = 0;

        for(int i=0; i<n; i++){
            long long cnt = calc(mn[0][i], mn[1][i], k);
            ans += 1LL*nums[i]*cnt;
        }

        for(int i=0; i<n; i++){
            long long cnt = calc(mx[0][i], mx[1][i], k);
            ans += 1LL*nums[i]*cnt;
        }

        return ans;


    }
};