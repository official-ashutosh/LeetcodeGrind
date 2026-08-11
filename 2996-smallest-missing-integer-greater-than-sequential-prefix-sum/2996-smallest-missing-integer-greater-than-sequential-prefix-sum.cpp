class Solution {
public:
    int missingInteger(vector<int>& nums) {
        vector<int> v(51,0);
        for(auto i : nums) v[i] = 1;
        int n = nums.size(), ans = INT_MAX;
        int j =0;
        int sum = nums[j];
        while(j+1 < n && nums[j+1] == nums[j]+1){
            sum += nums[j+1];
            j++;
        }

        while(true){
            if(sum > 50 || !v[sum]) return sum;
            sum++;
        }
        

        return 0;
    }
};