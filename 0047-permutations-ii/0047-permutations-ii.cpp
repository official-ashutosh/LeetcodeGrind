class Solution {
public:
    vector<vector<int>> ans;

    void func(vector<int>& nums, vector<int>& cr, vector<int>& used) {
        if(cr.size() == nums.size()){
            ans.push_back(cr);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(used[i]) continue;

            if(i > 0 && nums[i] == nums[i-1] && !used[i-1])
                continue;

            used[i] = 1;
            cr.push_back(nums[i]);

            func(nums, cr, used);

            cr.pop_back();
            used[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> cr;
        vector<int> used(nums.size(), 0);

        func(nums, cr, used);

        return ans;
    }
};