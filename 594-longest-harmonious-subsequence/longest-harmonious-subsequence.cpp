class Solution {
public:
    int findLHS(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int ans = 0;

        int  n = nums.size();
        for(int i=0; i<n-1; i++){
            auto it = upper_bound(nums.begin(), nums.end(), nums[i]+1);
            
            if(it != nums.begin()){
                it--;

                if(*it == nums[i]+1){
                    int r = it-nums.begin();
                    ans = max(ans, r-i+1);
                }
            }
        }


        return ans;
    }
};