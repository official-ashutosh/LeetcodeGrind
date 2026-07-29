class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ct1 = 0, ct2 = 0;
        for(auto i : nums){
            ct1 = (ct1 ^ i) & (~ct2);
            ct2 = (ct2 ^ i) & (~ct1);
        }

        return ct1;
    }
};