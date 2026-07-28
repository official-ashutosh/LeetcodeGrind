class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        int n = nums.size();

        int mx = 0;
        for(auto i : nums) mx = max(mx, i);

        vector<int> lst(mx+1, -1);
        for(int i=0; i<n; i++){
            for(int j=1; j*j<=nums[i]; j++){
                if(nums[i] % j == 0){
                    lst[j] = i;
                    int p = nums[i]/j;
                    if(p != j) lst[p] = i;

                }
            }
        }

        int i = 0, rs = 0;
        while(i <= rs){

            for(int j=1; j*j<=nums[i]; j++){
                if(nums[i] % j == 0){
                    if(j != 1) rs = max(rs, lst[j]);
                    int k = nums[i]/j;
                    if(k != 1) rs = max(rs, lst[k]);
                }
            }

            i++;
        }

        if(i == n) return -1;
        return i-1;

     

    }
};