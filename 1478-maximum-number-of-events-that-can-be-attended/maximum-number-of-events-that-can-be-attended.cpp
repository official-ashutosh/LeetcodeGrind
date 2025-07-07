class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        int ct, ans = 0, n = events.size();
        multiset<int> s;        
        int i = 0;

        ct = n>0 ? events[0][0] : 0;

        while (i < n || !s.empty()) {
            while (i < n && events[i][0] <= ct) {
                s.insert(events[i][1]);
                i++;
            }
            while (!s.empty() && *s.begin() < ct) {
                s.erase(s.begin());
            }
            if (!s.empty()) {
                ans++;
                s.erase(s.begin());
                ct++;
            }
            else if (i < n) {
                ct = events[i][0];
            }
        }

        return ans;
    }
};
