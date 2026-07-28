class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<double, int> mp;
        for(auto i : rectangles){
            double p = (i[0]*1.0)/(i[1]*1.0);
            mp[p]++;
        }

        long long ans = 0;
        for(auto i : mp){

            cout << i.first << " ";
            long long ct = i.second;
            ans += (ct*(ct-1))/2;
        }

        return ans;
    }
};