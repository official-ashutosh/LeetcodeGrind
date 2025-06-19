class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int ct = 1;
        int mn = nums[0];

        for(int i=1; i<nums.size(); i++){
            if(nums[i] > mn + k){
                mn = nums[i];
                ct++;
            }
        }

        return ct;

    }
};