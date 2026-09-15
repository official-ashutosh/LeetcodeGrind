class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string ans;
        int n = path.size();
        for(int i=0; i<n; i++){
            if(path[i] == '/') continue;

            string s;
            while(i < path.size() && path[i] != '/') {
                s += path[i];
                i++;
            }

            if(s == ".") continue;

            if(s == ".."){
                if(!st.empty()) st.pop();
            } else {
                st.push(s);
            }



        } 

        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }

        if(ans.size() == 0) ans += "/";
        return ans;
    }
};