class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> s;
        for(auto i : nums) s.insert(i);

        int ans = 0;
        for(auto i : s) {
            if(i > 0) ans += i;
        }

        if(*s.rbegin() < 0) return *s.rbegin();

        return ans;
    }
};