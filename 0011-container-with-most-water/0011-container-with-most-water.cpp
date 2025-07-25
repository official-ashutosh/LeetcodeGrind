class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;

        int n = height.size();
        int l = 0, r = n-1;


        while(l < r){
            int p1 = (r-l)*min(height[l], height[r]);
            ans = max(ans, p1);
            
            if(height[l] < height[r]) l++;
            else r--;
        }

        return ans;
    }
};