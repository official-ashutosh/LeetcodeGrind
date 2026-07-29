class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size()+1;
        int ans = 0;
        vector<int> pre(n, 0);

        for(int i=1; i<n; i++){
            pre[i] = pre[i-1]^arr[i-1];
        }

        unordered_map<int, int> mp1, mp2;
        for(int i=0; i<n; i++){
            ans += mp1[pre[i]]*(i-1) - mp2[pre[i]];
            mp1[pre[i]]++;
            mp2[pre[i]] += i;
        }

        return ans;
    }
};