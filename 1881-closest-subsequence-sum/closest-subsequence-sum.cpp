class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        vector<int> le, ri;

        int n = nums.size();

        // if(n == 1) {
        //     return minabs(goal-nums[0]);
        // }

        int n1 = n/2;
        int n2 = n-n1;

        for(int i=0; i<n1; i++) le.push_back(nums[i]);

        for(int i=n1; i<n; i++) ri.push_back(nums[i]);

        set<long long> sum1, sum2;

        for(int i=0; i<(1<<n1); i++){
            
            long long sum = 0;
            for(int j=0; j<n1; j++){
                if((1<<j) & i) sum += le[j];
            }

            sum1.insert(sum);
        }


        for(int i=0; i<(1<<n2); i++){
            
            long long sum = 0;
            for(int j=0; j<n2; j++){
                if((1<<j) & i) sum += ri[j];
            }

            sum2.insert(sum);
        }


        long long ans = 1e17;
        for(auto i : sum1){
            auto it = sum2.lower_bound(goal-i);

            if(it != sum2.end()){
                ans = min(ans, abs(i+(*it)-goal));
            }
            
            if(it != sum2.begin()){
                it--;
                ans = min(ans, abs(i+(*it)-goal));
            }
        }

        return ans;

    }
};