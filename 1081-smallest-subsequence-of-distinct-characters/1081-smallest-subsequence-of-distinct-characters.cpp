class Solution {
public:
    string smallestSubsequence(string s) {
        map<char, int> mp;
        int n = s.size();

        for(auto i : s) {
            mp[i]++;
        }

        map<char, int> mp2;
        deque<char> st;    

        for(auto i : s) {
            mp[i]--;
            if(mp2[i]) continue;
            
            while(!st.empty() && st.back() > i && mp[st.back()] > 0) {
                mp2[st.back()] = 0;
                st.pop_back();
            }
            st.push_back(i);
            mp2[i] = 1;
        }
        string ans;

        for(auto i : st) ans += i;
        return ans;
    }
};