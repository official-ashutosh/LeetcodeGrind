class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 1, r = 3000, ans = 1;
        while(l <= r){
            int mid = (l+r)/2;
            auto it = upper_bound(arr.begin(), arr.end(), mid);
            
                int id = it-arr.begin();
                if(mid-id >= k) {
                    ans = mid;
                    r = mid-1;
                }
                else l = mid+1;
            
        }
        return ans;
    }
};