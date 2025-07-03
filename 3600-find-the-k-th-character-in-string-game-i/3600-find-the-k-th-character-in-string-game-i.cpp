class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(s.size() < k){
            string p = s;
            for(int i=0; i<p.size(); i++){
                if(p[i] == 'z') p[i] = 'a';
                else p[i]++;
            }

            s = s+p;
        }

        return s[k-1];
    }
};