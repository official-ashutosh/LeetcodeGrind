class Solution {
    void combination(vector<int>& candidates, int target, vector<int> cr, int sm, int id, vector<vector<int>>& ans){
        if(sm > target) return; 
        if(sm==target){
            ans.push_back(cr); 
            return;
        }
        
        for(int i=id; i<candidates.size(); i++){ 
            cr.push_back(candidates[i]); 
            sm += candidates[i];
            combination(candidates, target, cr, sm, i, ans); 
            cr.pop_back(); 
            sm -= candidates[i];
        }
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;

        vector<int> cr;
        combination(candidates, target, cr, 0, 0, ans);
        return ans;
    }
};