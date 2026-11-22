class Solution {
public:
    bool checkString(string s) {
        
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i] == 'b'){
                while(i < n){
                    if(s[i] == 'a') return false;
                    i++;
                }

            }
        }

        return true;
    }
};