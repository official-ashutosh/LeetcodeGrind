class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<int> st;

        int n = s.size();

        int ans = 0;

        if(x > y) {

            for(int i=0; i<n; i++) {
                if(s[i] == 'b') {
                    if(!st.empty() && s[st.top()] == 'a') {
                        ans += x;
                        st.pop();
                    } else {
                        st.push(i);
                    }

                } else {
                    st.push(i);
                }
            }

            stack<int> st2;

            while(!st.empty()) {
                int id = st.top(); 
                st.pop();
                char c = s[id];
                if(c == 'b' && !st2.empty() && s[st2.top()] == 'a') {
                    ans += y;
                    st2.pop();

                } else {
                    st2.push(id);
                }
            }

        } else {

            for(int i=0; i<n; i++) {
                if(s[i] == 'a') {
                    if(!st.empty() && s[st.top()] == 'b') {
                        ans += y;
                        st.pop();
                    } else {
                        st.push(i);
                    }

                } else {
                    st.push(i);
                }
            }

            stack<int> st2;

            while(!st.empty()) {
                int id = st.top(); 
                st.pop();
                char c = s[id];
                if(c == 'a' && !st2.empty() && s[st2.top()] == 'b') {
                    ans += x;
                    st2.pop();

                } else {
                    st2.push(id);
                }
            }
        }

        return ans;
    }
};
