class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> s;

        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == key){
                int ct = 0;
                int j = i;
                while(j >= 0 && ct <= k){
                    s.insert(j);
                    ct++;
                    j--;
                }

                j = i;
                ct = 0;
                while(j < n && ct <= k){
                    s.insert(j);
                    ct++;
                    j++;
                }


            }
        }

        vector<int> ans;
        for(auto i : s) ans.push_back(i);

        return ans;
    }
};