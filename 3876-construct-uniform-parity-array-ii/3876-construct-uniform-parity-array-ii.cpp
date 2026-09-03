class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn1 = INT_MAX, mn2 = INT_MAX;
        for(auto i : nums1){
            if(i % 2) mn1 = min(mn1, i);
            else mn2 = min(mn2, i);
        }

        if(mn1 == INT_MAX) return true;
        if(mn1 > mn2) return false;
        return true;
    }
};