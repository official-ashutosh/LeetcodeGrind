class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        map<int, int> mp;
        for(auto c : s) mp[c-'a']++;

        string ans;
        int n = s.size();
        int i = 0;

        while(i < n && mp[target[i]-'a']) {
            ans += target[i];
            mp[target[i]-'a']--;
            i++;
        }

        if(i < n){
            for(char c = target[i]+1; c <= 'z'; c++){
                if(mp[c - 'a']) {
                    ans += c;
                    mp[c-'a']--;

                    for(int j=0; j<26; j++)
                        ans += string(mp[j], 'a'+j);

                    return ans;
                }
            }
        }

        for(i = ans.size()-1; i>=0; i--){
            mp[ans[i]-'a']++;
            ans.pop_back();

            for(char c = target[i]+1; c<='z'; c++) {
                if(mp[c-'a']){
                    ans += c;
                    mp[c-'a']--;

                    for(int j=0; j<26; j++)
                        ans += string(mp[j], 'a'+j);

                    return ans;
                }
            }
        }

        return "";
    }
};