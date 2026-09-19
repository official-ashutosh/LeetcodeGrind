class Solution {
public:
    vector<string> ans;

    void func(string &s, int id, int ct, string cr) {
        if(ct == 4){
            if(id == s.size()){
                cr.pop_back();
                ans.push_back(cr);
            }
            return;
        }

        for(int i=1; i<=3 && id+i <= s.size(); i++){
            string part = s.substr(id, i);

            if(part.size() > 1 && part[0] == '0') break;
            if(stoi(part) > 255) break;

            func(s, id+i, ct+1, cr + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s){
        if(s.size() < 4 || s.size() > 12) return ans;

        func(s, 0, 0, "");
        return ans;
    }
};