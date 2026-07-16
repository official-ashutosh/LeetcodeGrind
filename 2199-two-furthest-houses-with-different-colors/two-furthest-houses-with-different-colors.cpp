class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0;
        int n = colors.size();
        for(int i=n-1; i>=0; i--){
            if(colors[i] != colors[0]){
                ans = i;
                break;
            }
        }

        reverse(colors.begin(), colors.end());
        for(int i=n-1; i>=0; i--){
            if(colors[i] != colors[0]){
                ans = max(ans,i);
                break;
            }
        }

        return ans;
    }
};