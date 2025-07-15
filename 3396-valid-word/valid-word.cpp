class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;
        
        int f = 0, f2 = 0;
        for (auto c : word) {
            if(isalpha(c)) {
                c = tolower(c);
                if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    f = 1;
                } else {
                    f2 = 1;
                }
            } else if(!isdigit(c)) return false;

        }
        return f && f2;
    }
};