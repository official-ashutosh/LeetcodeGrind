class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        vector<pair<int, int>> v;

        for(int i=0; i<nums.size(); i++){
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end(), greater<pair<int, int>>());

        for(int i=0; i<k; i++){
            ans.push_back(v[i].second);
        }

        sort(ans.begin(), ans.end());

        for(auto &i : ans){
            i = nums[i];
        }

        return ans;
    }
};