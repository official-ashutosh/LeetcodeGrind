class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0, ct = 1;

        for(int i=1; i<nums.size(); i++){
            if(nums[i] != nums[j]){
                ct = 1;
                nums[++j] = nums[i];
            } else {
                if(ct == 1){
                    nums[++j] = nums[i];
                }
                ct++;
            }
        }

        return j+1;
    }
};