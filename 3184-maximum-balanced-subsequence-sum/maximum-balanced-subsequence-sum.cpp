class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        long long mx = nums[0];

        for (auto i : nums) {
            mx = max(mx, (long long)i);
        }

        if (mx <= 0)
            return mx;

        // key = nums[i] - i
        // {best sum ending with this key, index}
        map<long long, pair<long long, long long>> mp;

        long long ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0)
                continue;

            long long key = (long long)nums[i] - i;

            // Best previous state having previous key <= current key
            auto j = mp.upper_bound(key);

            long long cur = nums[i];

            if (j != mp.begin()) {
                --j;
                cur = max(cur, nums[i] + j->second.first);
            }

            ans = max(ans, cur);

            // Same key already exists
            auto it = mp.find(key);

            if (it != mp.end()) {
                if (it->second.first >= cur)
                    continue;

                it->second = {cur, i};
            } else {
                it = mp.insert({key, {cur, i}}).first;
            }

            /*
                Remove states to the right that are dominated by
                the current state.

                If current key is >= old key and current sum is >= old sum,
                old state can never be better for any future element.
            */
            auto k = next(it);

            while (k != mp.end() && k->second.first <= cur) {
                auto temp = k;
                ++k;
                mp.erase(temp);
            }
        }

        return max(ans, mx);
    }
};