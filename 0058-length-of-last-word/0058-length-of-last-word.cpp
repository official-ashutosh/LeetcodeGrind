class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int fl = 0;
        for(int i=s.size()-1; i>=0; i--){
            if(fl && s[i] ==' ') break;
            if(s[i] != ' ') {
                fl = 1;
                ans++;
            }
        }

        return ans;
    }
};