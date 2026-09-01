class Solution {
public:
    vector<string> ans;
    unordered_map<string, int> mp;
    void func(int id, string &s, string &ans_s, string &p){
        if(id == s.size()){
            if(mp[p]) ans.push_back(ans_s); 
            return;
        }

        if(p.size() < 10){
        ans_s += s[id];
        p += s[id];
        func(id+1, s, ans_s, p);
        ans_s.pop_back();
        p.pop_back();
        }

        if(mp[p]){
            ans_s += " ";
            string temp = p;
            p = "";
            func(id, s, ans_s, p);
            p = temp;
            ans_s.pop_back();
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto i : wordDict) mp[i] = 1; 
        string ans_s, p; 
        func(0, s, ans_s,p);
        return ans;
    }
};