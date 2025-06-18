class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& a, int k) {
        vector<vector<int>> ans;
        
        sort(a.begin(), a.end());
        for(int i=0; i<a.size(); i+=3){
            if(a[i+2]-a[i] > k) return {};

            ans.push_back({a[i], a[i+1], a[i+2]});
        }

        return ans;
    }
};