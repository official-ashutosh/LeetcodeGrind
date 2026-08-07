class Solution {
public:

    int merge_count(int l, int r, vector<int> &nums){
        int mid = (l+r)/2;

        int n1 = mid-l+1;
        int n2 = r-mid;
        vector<int> le(n1), ri(n2);

        for(int i=0; i<n1; i++){
            le[i] = nums[l+i];
        }

        for(int j=0; j<n2; j++){
            ri[j] = nums[mid+j+1];
        }

        int ans = 0;
        int i=0, j=0;
        for(i=0; i<n1; i++){
            while(j < n2 && (le[i]) > 2ll*ri[j]) j++;
            ans += j;
        }

        i = 0, j = 0;
        int k = l;
        while(i < n1 && j < n2){
            if(le[i] <= ri[j]){
                nums[k++] = le[i++];
            } else {
                nums[k++] = ri[j++];
            }
        }

        while(i < n1){
            nums[k++] = le[i++];
        }

        while(j < n2){
            nums[k++] = ri[j++];
        }

        return ans;
    }

    int mergesort(int l, int r, vector<int>&nums){
            int ans = 0;
        if(l < r){
            int mid = (l+r)/2;

            ans += mergesort(l, mid, nums);
            ans += mergesort(mid+1, r, nums);

            ans += merge_count(l, r, nums);
        }
        return ans;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        int ans = mergesort(0, n-1, nums);
        return ans;
    }
};