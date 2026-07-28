class Solution {
public:
    string smallestPalindrome(string s) {
        int len = s.length();
        int p = len / 2;

        sort(s.begin(), s.begin() + p);

        for(int i = 0; i < p; ++i) {
            s[len-1-i] = s[i];
        }

        return s;
    }
};