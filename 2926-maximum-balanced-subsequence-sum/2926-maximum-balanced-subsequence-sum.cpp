class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        long long mx = nums[0];

        for(auto i : nums){
            mx = max(mx, (long long)i);
        }

        if(mx <= 0)
            return mx;

        // key = nums[i] - i
        // {best sum ending with this key, index}
        map<long long, pair<long long, long long>> mp;

        long long ans = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] <= 0)
                continue;

            long long key = nums[i]-i;

            auto j = mp.upper_bound(key);

            long long cur = nums[i];

            if(j != mp.begin()){
                --j;
                cur += j->second.first;
            }

            ans = max(ans, cur);

            auto it = mp.find(key);

            if(it != mp.end()){
                if(it->second.first >= cur)
                    continue;

                it->second = {cur, i};
            } else {
                it = mp.insert({key, {cur, i}}).first;
            }

            auto k = next(it);

            while(k != mp.end() && k->second.first <= cur){
                auto temp = k;
                k++;
                mp.erase(temp);
            }
        }

        return max(ans, mx);
    }
};