class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());

        set<string> st;
        string ans;

        for(auto &w : words) {
            if(w.size() == 1 || st.count(w.substr(0, w.size()-1))){
                st.insert(w);

                if(w.size() > ans.size()) ans = w;
            }
        }

        return ans;
    }
};