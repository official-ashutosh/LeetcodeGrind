class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int ct = 0;
        char c = '*';

        for(auto i : s){
            if(i == c) ct++;
            else {
                ct = 1;
                c = i;
            }

            if(ct < 3) ans += i;
        }

        return ans;
    }
};