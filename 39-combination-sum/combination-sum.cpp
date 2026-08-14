class Solution {
    void combination(vector<int>& candidates, int target, vector<int> cr, int sm, int id, vector<vector<int>>& ans){
        if(sm > target || id == candidates.size()) return;
        if(sm == target){
            ans.push_back(cr);
            return;
        }

        cr.push_back(candidates[id]);
        combination(candidates, target, cr, sm + candidates[id], id, ans);
        cr.pop_back();

        combination(candidates, target, cr, sm, id + 1, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cr;
        combination(candidates, target, cr, 0, 0, ans);
        return ans;
    }
};