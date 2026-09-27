class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1) {
            string ans = s;

            for(int i=1; i<s.size(); i++){
                string cur = s.substr(i) + s.substr(0, i);
                ans = min(ans, cur);
            }

            return ans;
        }

        sort(s.begin(), s.end());
        return s;
    }
};