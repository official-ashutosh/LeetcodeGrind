class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int ct = 0, j = 0, c1 = 0, c2 = 0, ans = 0;
        char prev = '*';

        for(auto c: s){
            ct += (c == '1');
        }

        string t = "1" + s + "1";
        vector<int> v;

        prev = t[0];
        c1 = 1;

        for(int i=1; i<t.size(); i++){
            if(t[i] == prev) c1++;
            else{
                v.push_back(c1);
                c1 = 1;
                prev = t[i];
            }
        }
        v.push_back(c1);

        for(int i=2; i<v.size()-1; i+=2){
            ans = max(ans, v[i-1] + v[i+1]);
        }

        ans += ct;
        return ans;
    }
};