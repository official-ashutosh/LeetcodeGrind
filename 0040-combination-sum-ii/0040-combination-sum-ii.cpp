class Solution {
    void combination(vector<int>& candidates, int target, vector<int> cr, int sm, int id, vector<vector<int>>& ans){
        if(sm == target){
            ans.push_back(cr);
            return;
        }
        if(sm > target || id == candidates.size()) return;

        cr.push_back(candidates[id]);
        combination(candidates, target, cr, sm + candidates[id], id + 1, ans);
        cr.pop_back();

        int i = id + 1;
        while(i < candidates.size() && candidates[i] == candidates[id])
            i++;

        combination(candidates, target, cr, sm, i, ans);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> cr;
        combination(candidates, target, cr, 0, 0, ans);

        return ans;
    }
};