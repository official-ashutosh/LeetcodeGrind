class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> pre(n+1, n), suff(n+1, n);
        int l = 0, sum = 0 ;
        for(int r=0; r<n; r++){
            sum += arr[r];
            while(sum > target){
                sum -= arr[l];
                l++;
            }

            pre[r+1] = pre[r];
            if(sum == target) pre[r+1] = min(pre[r], r-l+1);
        }

        int r = n-1;
        sum = 0;
        for(int l=n-1; l>=0; l--){
            sum += arr[l];
            while(sum > target){
                sum -= arr[r];
                r--;
            }

            suff[l] = suff[l+1];
            if(sum == target) suff[l] = min(suff[l+1], r-l+1);
        }

        int ans = n+1;
        for(int i=0; i<n-1; i++){
            ans = min(ans, pre[i+1]+suff[i+1]);
        }
        if(ans > n) ans = -1;
        return ans;
    }
};