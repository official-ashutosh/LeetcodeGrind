class Solution {
public:
    int minOperations(string s) {
        int c1 = 0, c2 = 0;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(i % 2 == 0) {
                if(s[i] == '0') c2++;
                else c1++;
            }
            else  {
                if(s[i] == '1') c2++;
                else c1++;
            }

        }

        return min(c1, c2);
    }
};