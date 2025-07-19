class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n-1;

        vector<int> v1, v2;
        v1.push_back(arr[0]);
        v2.push_back(arr[n-1]);

        for(int i=1; i<n; i++){
            if(arr[i] <= arr[i-1]) break;
            l++;
            v1.push_back(arr[l]);
        }

        for(int i=n-2; i>=0; i--){
            if(arr[i+1] <= arr[i]) break;
            r--;
            v2.push_back(arr[r]);
        }

        if(l == n-1) {
            long long ans = (long long)(n+1)*(n)/2;

            return ans;
        }

        reverse(v2.begin(), v2.end());

        long long ans = 1;

        long long m = v2.size();
        int j = 0;
        for(int i=0; i<v1.size(); i++){
            int ct = 0;
            while(j < m && arr[i] >= v2[j]){
                ct++;
                j++;
            }

            ans += (m-j+1);
            ans += ct;

            cout << ans << " ";
        }
        ans += (m-j);

        return ans;
    }
};