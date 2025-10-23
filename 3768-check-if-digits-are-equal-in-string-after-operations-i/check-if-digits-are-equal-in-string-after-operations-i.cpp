class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.length() > 2){
            string k; 
            for(int i=0; i<s.length()-1; i++){
                k += to_string((s[i]+s[i+1]-'0'-'0') % 10);
            }
            s = k;
        }

        return s[0] == s[1];
    }
};