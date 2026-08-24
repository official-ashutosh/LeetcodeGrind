class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {

        long long ans = 0;
        multiset<pair<int, int>> ms1, ms2;
        int n = costs.size();

        int le = 0, ri = n-1;
        for(int i=0; i<candidates; i++){
            ms1.insert({costs[i], i});
            ms2.insert({costs[n-1-i], n-i-1});
            le++;
            ri--;
        }

        while(k--){

            pair<int, int> mn1 = {INT_MAX, INT_MAX};
            pair<int, int> mn2 = {INT_MAX, INT_MAX};

            if(ms1.size() > 0) mn1 = *ms1.begin();
            if(ms2.size() > 0) mn2 = *ms2.begin();

            if(mn1.first <= mn2.first){
                ans += mn1.first;
                if(le <= ri) 
                    ms1.insert({costs[le], le});
                le++;
                
                ms1.erase(mn1);
                
                if(ms2.count(mn1)){
                    ms2.erase(mn1);
                    if(ri >= le){
                        ms2.insert({costs[ri], ri});
                    }
                    ri--;
                }
            } else {
                ans += mn2.first;

                if(ri >= le)
                    ms2.insert({costs[ri], ri});
                
                ri--;
                ms2.erase(mn2);

                if(ms1.count(mn2)){
                    ms1.erase(mn2);
                    if(le <= ri) 
                    ms1.insert({costs[le], le});
                    le++;
                }
            }

            cout << ans << " ";

        }

        return ans;


    }
};