class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans = 0;
        for(auto i : nums){
            for(int j=0; j<30; j++){
                if(i & (1ll<<j)) ans |= (1ll<<j);
            }
        }

        return ans;
    }
};