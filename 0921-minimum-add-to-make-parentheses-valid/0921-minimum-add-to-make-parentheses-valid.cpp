class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        stack<char> st;

        for(auto i : s){
            if(i == '('){
                st.push(i);
            } else {
                if(st.size() > 0) st.pop();
                else ans++;
            }
        }

        ans += st.size();

        return ans;
    }
};