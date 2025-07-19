class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n-1;

        vector<int> v1, v2;
        v1.push_back(arr[0]);
        v2.push_back(arr[n-1]);

        for(int i=1; i<n; i++){
            if(arr[i] < arr[i-1]) break;
            l++;
            v1.push_back(arr[l]);
        }

        for(int i=n-2; i>=0; i--){
            if(arr[i+1] < arr[i]) break;
            r--;
            v2.push_back(arr[r]);
        }

        if(l >= r) return 0;

        reverse(v2.begin(), v2.end());

        int ans = max(l+1, n-r);

        int m = v2.size();
        for(int i=0; i<v1.size(); i++){
            int ans2 = i+1;
            ans2 += m - (lower_bound(v2.begin(), v2.end(), v1[i])-v2.begin());
            ans = max(ans, ans2);
        }

        return n-ans;

    }
};