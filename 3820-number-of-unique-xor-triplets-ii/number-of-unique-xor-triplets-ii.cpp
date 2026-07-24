class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int mx = 0;
        for(auto i : nums) mx = max(mx, i);

        int m = mx*2;

        vector<int> v1(m), v2(m), v3(m);

        for(auto i : nums){
            v1[i] = 1;

            for(int j=0; j<m; j++){
                if(v1[j]){
                    v2[j^i] = 1;
                }
            }
        }

        for(auto i : nums){
            for(int j=0; j<m; j++){
                if(v2[j]){
                    v3[j^i] = 1;
                }
            }
        }

        int ans = 0;
        for(int i=0; i<m; i++){
            ans += v3[i];
        }

        return ans;

    }
};