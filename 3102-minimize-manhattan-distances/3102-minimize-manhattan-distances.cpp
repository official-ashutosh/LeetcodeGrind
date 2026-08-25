class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        multiset<int> ms1, ms2;
        for(auto i : points){
            ms1.insert(i[0]+i[1]);
            ms2.insert(i[0]-i[1]);
        }

        int ans1 = *(--ms1.end())-*ms1.begin();
        int ans2 = *(--ms2.end())-*ms2.begin();
        int ans = max(ans1, ans2);

        for(auto i : points){
            ms1.erase(ms1.find(i[0]+i[1]));
            ms2.erase(ms2.find(i[0]-i[1]));
            
            ans1 = *(--ms1.end())-*ms1.begin();
            ans2 = *(--ms2.end())-*ms2.begin();
            ans = min(ans, max(ans1, ans2));

            ms1.insert(i[0]+i[1]);
            ms2.insert(i[0]-i[1]);
        }

        return ans;
    }
};