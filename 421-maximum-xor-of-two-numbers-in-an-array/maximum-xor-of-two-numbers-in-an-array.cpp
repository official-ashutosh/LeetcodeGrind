class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0, mask = 0;

        for(int i=31; i>=0; i--) {
            mask |= (1 << i);
            unordered_set<int> prefixes;
            for(auto num : nums) {
                prefixes.insert(num & mask);
            }
            
            int ans2 = ans | (1 << i);
            for(auto p : prefixes) {
                if(prefixes.count(p ^ ans2)) {
                    ans = ans2;
                    break;
                }
            }
        }
        return ans;
    }
};
