class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, int> mp;
        int n = s.size();

        for(auto i : s) {
            mp[i]++;
        }

        map<char, int> used;
        deque<char> st;    

        for(auto i : s) {
            mp[i]--;
            if(used[i]) continue;
            
            while(!st.empty() && st.back() > i && mp[st.back()] > 0) {
                used[st.back()] = false;
                st.pop_back();
            }
            st.push_back(i);
            used[i] = true;
        }
        string ans;

        for(int x : st) ans += char(x);
        return ans;
    }
};
