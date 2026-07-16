class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        int mx = arr.back();
        for(int i=n-2; i>=0; i--){
            ans[i] = mx;
            mx = max(mx, arr[i]);
        }

        return ans;

    }
};