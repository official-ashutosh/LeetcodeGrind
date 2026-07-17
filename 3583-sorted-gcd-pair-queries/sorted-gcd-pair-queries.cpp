class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        vector<long long> v(50010);

        for(auto i : nums){
            v[i]++;
        }

        for(int i=1; i<50010; i++){
            for(int j=2*i; j<50010; j+=i){
                v[i] += v[j];
            }
        }

        for(int i=1; i<50010; i++){
            v[i] = (v[i]*(v[i]-1))/2;
        }

        for(int i=50009; i>0; i--){
            for(int j=2*i; j<50010; j+=i){
                v[i] -= v[j];
            }
        }

        for(int i=1; i<50010; i++){
            v[i] += v[i-1];
        }

        vector<int> ans;
        for(auto q : queries){
            int id = lower_bound(v.begin(), v.end(), q+1) - v.begin();
            ans.push_back(id);
        }

        return ans;
    }
};