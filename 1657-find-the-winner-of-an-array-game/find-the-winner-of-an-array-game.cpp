class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();

        int ans = arr[0];
        int ct = 0;

        for(int i=1; i<n; i++){
            if(ans > arr[i]){
                ct++;
            } else {
                ans = arr[i];
                ct = 1;
            }

            if(ct >= k) return ans;
        }

        return ans;
    }
};