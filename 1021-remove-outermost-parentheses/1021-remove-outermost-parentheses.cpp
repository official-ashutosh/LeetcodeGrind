class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        stack<char> st, st2;

        int d = 0;
        for(auto i : s){
            if(i == '('){
                if(d > 0) ans += i;
                d++;
            } else {
                d--;
                if(d > 0) ans += i;
            }
        }

        return ans;
    }
};
