class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;

        for(auto &word : words){
            map<char, char> mp1, mp2;
            int fl = 1;

            for(int i=0; i<word.size(); i++){
                if(mp1.count(word[i]) && mp1[word[i]] != pattern[i]){
                    fl = 0;
                    break;
                }
                if(mp2.count(pattern[i]) && mp2[pattern[i]] != word[i]){
                    fl = 0;
                    break;
                }

                mp1[word[i]] = pattern[i];
                mp2[pattern[i]] = word[i];
            }

            if(fl) ans.push_back(word);
        }

        return ans;
    }
};