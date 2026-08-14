class Solution {
public:

    void func(int id, vector<int> &v, vector<vector<int>> &ans, vector<int> &nums){
        if(id == nums.size()){
            ans.push_back(v);
            return;
        }

        v.push_back(nums[id]);
        func(id+1, v, ans, nums);
        v.pop_back();

        int i = id+1;
        while(i < nums.size() && nums[i] == nums[id]) i++;
        func(i, v, ans, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector< int> v;
        func(0, v, ans, nums);
        return ans;    
    }
};