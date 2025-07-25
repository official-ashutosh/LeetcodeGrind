class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int,int> mp;
        for(auto x:nums) mp[x]++;
        
        while(1){
            if(mp.find(original) == mp.end()){
                return original;
            }
            original = original*2;
        }
        return -1;
    }
};