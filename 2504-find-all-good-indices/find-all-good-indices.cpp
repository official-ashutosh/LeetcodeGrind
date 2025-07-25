class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> ans;
        if(k == 1){
            for(int i=1; i<n-1; i++) ans.push_back(i);
        } else {

            vector<int> v(n, 0);
            int ct = 1;
            for(int i=n-2; i>0; i--){
                if(nums[i] > nums[i+1]) ct = 1;
                else ct++;


                if(ct >= k) v[i-1]++;
            }

            ct = 1;

            for(int i=1; i<n-1; i++){
                if(nums[i] > nums[i-1]) ct = 1;
                else ct++;

                if(ct >= k) v[i+1]++;
            }

            for(int i=1; i<n; i++){
                if(v[i] == 2) ans.push_back(i);
            }
        }

        return ans;
    }
};