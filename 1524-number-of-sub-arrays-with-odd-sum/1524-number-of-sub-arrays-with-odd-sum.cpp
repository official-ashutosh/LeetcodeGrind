class Solution {
public:
    const int mod = 1e9 + 7;

    int numOfSubarrays(vector<int>& arr) {
        int odd = 0, even = 0, ans = 0;

        for(auto i : arr) {
            if(i % 2){
                swap(odd, even);
                odd++;
            } else {
                even++;
            }

            ans = (ans + odd) % mod;
        }

        return ans;
    }
};