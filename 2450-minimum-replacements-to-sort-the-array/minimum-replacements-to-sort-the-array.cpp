class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        while(nums.size() > 1){
            int m = nums.size();
            int a = nums[m-1];
            int c = nums[m-2];

            nums.pop_back();

            if(a < c){
                int d = c/a;
                nums.pop_back();

                if(c % a == 0){
                    ans += (d-1);
                    nums.push_back(a);

                } else {
                    
                    d++;
                    int p = c/d;
                    nums.push_back(p);
                    ans+=(d-1);
                }
            }
        }

        return ans;
    }
};