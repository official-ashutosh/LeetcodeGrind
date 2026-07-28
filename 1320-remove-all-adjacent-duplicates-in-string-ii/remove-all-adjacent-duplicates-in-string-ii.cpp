class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char> st;
        stack<int> st2;
        int n = s.size();
        int i = 1;
        st.push(s[0]);
        st2.push(1);

        for(int i=1; i<n; i++){
            if(st.empty()) {
                st.push(s[i]);
                st2.push(1);
            }
            else {
                if(st.top() == s[i]){
                    if(st2.top() == k-1) {
                        st.pop();
                        st2.pop();
                    }
                    else st2.top()++;
                } else {
                    st.push(s[i]);
                    st2.push(1);
                }
            }
        }

        string ans;
        while(!st.empty()){

            int ct = st2.top();
            while(ct--){
                ans += st.top();
            }
            st.pop();
            st2.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};