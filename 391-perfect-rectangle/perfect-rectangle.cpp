class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long long area = 0;

        set<pair<int, int>> s;
        int mn1 = INT_MAX, mn2 = INT_MAX,mx1 = INT_MIN, mx2 = INT_MIN;
        for(auto i : rectangles){
            mn1 = min({mn1, i[0], i[2]});
            mn2 = min({mn2, i[1], i[3]});
     
            mx1 = max({mx1, i[0], i[2]});
            mx2 = max({mx2, i[1], i[3]});
            
            area += (long long)(i[2]-i[0])*(i[3]-i[1]);
            vector<pair<int, int>> v;
            v.push_back({i[0], i[1]});
            v.push_back({i[0], i[3]});
            v.push_back({i[2], i[1]});
            v.push_back({i[2], i[3]});


            for(auto j : v){
                if(s.count(j)) s.erase(j);
                else s.insert(j);
            }
        }

        set<pair<int, int>> s2;
        s2.insert({mn1, mn2});
        s2.insert({mn1, mx2});
        s2.insert({mx1, mn2});
        s2.insert({mx1, mx2});

        cout << mn1 << " " << mn2 << " " << mx1 << " " << mx2 << endl;

        long long area2 = (long long)(mx1-mn1)*(mx2-mn2);

        return area == area2 && (s == s2);
    }
};